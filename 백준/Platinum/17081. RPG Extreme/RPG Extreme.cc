#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct coord {
	int x = 0, y = 0;
};

// 게임종료 원인 출력용
enum eEndCause {
	endNone, win, progress, killedByBoss, killedByTrap, killedByMob
};
// 맵
class grid {
public:
	coord size;
	char objs[101][101] = { 0, };	// 맵 내 내용물
	int mobNum = 0, itemNum = 0;
	bool traps[101][101];	// ^ 지속대미지 판정 위함
	int turn = 0;
	int endCause = endNone;
	string killer;
	int playerStartX = 0, playerStartY = 0;
	int bossX = 0, bossY = 0;
};
grid map;

// 부모
// 상태
enum eUnitState {
	die, alive
};
class unit {
public:
	coord pos = { 0, 0 };
	int hp = 0, maxHp = 0;
	int atk = 0, def = 0;
	int level = 0, exp = 0;
	int state = alive;

	// 피격
	void hit(int damage) {
		hp += damage;
		if (hp <= 0) {
			hp = 0;
			state = die;
		}
	}
};


// 몹
enum eMobGrade {
	normal, boss
};
class mob : public unit {
public:
	string name;
	int grade = normal;
};
vector<mob> mobs;


// 아이템
enum eItemType {
	itemNone, weapon, armor, acc
};
enum eAccType {
	accNone, HR, RE, CO, EX, DX, HU, CU
};
class item : public unit {
public:
	int type = itemNone;
	int accType = accNone;
};
vector<item> items;


// 플레이어
const int accMax = 4;
class player : public unit {
public:
	item equippedWeapon;
	item equippedArmor;
	item equippedAccs[accMax];

	// 초기화
	void initPlayer() {
		maxHp = 20;
		hp = maxHp;
		atk = 2;
		def = 2;
		exp = 0;
		level = 1;
		pos.x = map.playerStartX;
		pos.y = map.playerStartY;
	}

	// 이동
	void move(char dir) {
		int nx = pos.x, ny = pos.y;

		switch (dir) {
		case 'R':	ny = pos.y + 1;		break;
		case 'L':	ny = pos.y - 1;		break;
		case 'U':	nx = pos.x - 1;		break;
		case 'D':	nx = pos.x + 1;		break;
		}

		if (isMovable(nx, ny)) {
			drawPriorForTrap();	// 이동 확정 전에 trap 체크하고 '.'인지, '^'인지 결정

			pos.x = nx;
			pos.y = ny;

			// 이동 후 표시는 encounter, battle 후 생존 판단 후.
		}
		else {
			// 이동할 수 없었으면 trap 체크해서 대미지
			if (map.traps[pos.x][pos.y]) {
				activeTrap();
			}
		}
	}

	// 이동 유효 검사
	bool isMovable(int nx, int ny) {
		// 그리드 범위
		if (nx <= 0 || nx > map.size.x ||
			ny <= 0 || ny > map.size.y) {
			return false;
		}
		// 벽
		return map.objs[nx][ny] != '#';
	}

	// 그래프 그리기
	void drawPriorForTrap() {
		if (map.traps[pos.x][pos.y]) {	// 함정 있었으면
			map.objs[pos.x][pos.y] = '^';
		}
		else {
			map.objs[pos.x][pos.y] = '.';
		}
	}

	// 조우
	void encounter() {
		switch (map.objs[pos.x][pos.y]) {

		case 'B': {	// 아이템
			for (auto& item : items) {
				if (item.pos.x == pos.x &&
					item.pos.y == pos.y) {
					equip(item.type, item.accType, item.atk, item.def);
					break;
				}
			}

			// 표시
			map.objs[pos.x][pos.y] = '@';

			break;
		}

		case '^': {	// 함정
			activeTrap();
			break;
		}

		case '&':	// 몬스터
		case 'M': {
			for (auto& mob : mobs) {
				if (mob.pos.x == pos.x &&
					mob.pos.y == pos.y) {
					// 전투
					battle(mob);
				}
			}
			break;
		}

		case '.': {	// 빈
			// 표시
			map.objs[pos.x][pos.y] = '@';
			break;
		}// case

		}// switch
	}

	// 트랩 발동 (이동 불가 시 지속 대미지)
	void activeTrap() {
		int damage = 5;
		if (hasAcc(DX)) {
			damage = invokeAccDX();
		}

		hit(-damage);

		if (state == alive) {
			// 표시
			map.objs[pos.x][pos.y] = '@';
		}

		if (state == die) {
			if (isRevival()) {	// 부활 했으면
				map.objs[map.playerStartX][map.playerStartY] = '@';
			}
			else {	// 부활 못했으면
				map.objs[pos.x][pos.y] = '^';
				map.endCause = killedByTrap;
				map.killer = "SPIKE TRAP";
			}
		}
	}

	// 사망 후 부활 검증 및 효과
	bool isRevival() {
		for (auto& acc : equippedAccs) {
			if (acc.accType == RE) {
				invokeAccRE(acc);
				return true;
			}
		}
		return false;
	}

	// 전투
	void battle(mob& monster) {

		// 악세 효과 세팅
		int coefAtk = 1;
		float coefExp = 1.0f;
		bool isDXDamageUp = false;
		bool firstAtkImmune = false;

		if (hasAcc(HU)) {
			invokeAccHU(firstAtkImmune);
		}
		if (hasAcc(DX)) {
			invokeAccDX(isDXDamageUp);
		}
		if (hasAcc(EX)) {
			coefExp = invokeAccEX();
		}

		if (hasAcc(CO)) {	// DX => CO 순서 판단
			coefAtk = invokeAccCO(isDXDamageUp);
		}

		// 대미지 공방
		while (1) {
			// 플레이어->적
			int damage = max(1, (atk + equippedWeapon.atk) * coefAtk - monster.def);
			monster.hit(-damage);

			if (coefAtk != 1) {	// 첫 공격만 뻠핑 후 원래대로
				coefAtk = 1;
			}

			if (monster.state == die) {	// 승리
				expUp(static_cast<int>(monster.exp * coefExp));

				if (hasAcc(HR)) {
					invokeAccHR();
				}

				// 표시
				map.objs[pos.x][pos.y] = '@';

				break;
			}

			// 적->플레이어
			// HU
			if (monster.grade == boss && firstAtkImmune) {
				firstAtkImmune = false;
				damage = 0;
			}
			else {
				damage = max(1, monster.atk - (def + equippedArmor.def));
			}
			hit(-damage);

			// 패배
			if (state == die) {
				if (isRevival()) {	// 부활 했으면
					map.objs[map.playerStartX][map.playerStartY] = '@';
				}
				else {	// 부활 못했으면
					if (monster.grade == boss) { map.endCause = killedByBoss; }
					else { map.endCause = killedByMob; }
					map.killer = monster.name;
				}

				break;
			}
		}
	}

	// 장비장착&교체
	void equip(int itemType, int itemAccType, int newWeaponAtk, int newArmorDef) {
		switch (itemType) {
		case weapon: {
			equippedWeapon.atk = newWeaponAtk;
			break;
		}
		case armor: {
			equippedArmor.def = newArmorDef;
			break;
		}

		case acc: {
			// 같은 acc 중복 불가, 빈 칸 있으면 장착
			bool equipPossible = true;
			for (auto& acc : equippedAccs) {
				if (acc.accType == itemAccType) {
					equipPossible = false;
					break;
				}
			}
			if (equipPossible) {
				for (auto& acc : equippedAccs) {
					if (acc.accType == accNone) {
						acc.accType = itemAccType;
						break;
					}
				}
			}
			break;
		}// case
		}// switch
	}

	// 렙업
	void expUp(int expDamage) {
		exp += expDamage;
		if (exp >= level * 5) {	// 레벨업
			maxHp += 5;
			hp = maxHp;
			atk += 2;
			def += 2;
			exp = 0;	// 남는 경험치 버려짐
			level++;
		}
	}

	// 악세서리 능력
	void invokeAccHR() {
		hp += 3;
		if (hp > maxHp) {
			hp = maxHp;
		}
	}

	// battle 사망 시 부활
	void invokeAccRE(item& acc, mob& monster) {
		monster.hp = monster.maxHp;
		invokeAccRE(acc);
	}

	// ^로 사망 시 부활
	void invokeAccRE(item& acc) {
		acc.accType = accNone;
		state = alive;
		hp = maxHp;
		pos.x = map.playerStartX;	// 처음 위치로.
		pos.y = map.playerStartY;
	}

	int invokeAccCO(bool& isDXDamageUp) {
		if (isDXDamageUp) { return 3; }
		else { return 2; }
	}

	float invokeAccEX() { return 1.2f; }

	// 함정 고정피해
	int invokeAccDX() { return 1; }

	// CO 공격효과 3배
	void invokeAccDX(bool& isDXDamageUp) { isDXDamageUp = true; }

	void invokeAccHU(bool& firstAtkImmune) {
		hp = maxHp;
		firstAtkImmune = true;
	}

	bool hasAcc(int accType) {
		for (auto& acc : equippedAccs) {
			if (acc.accType == accType) { return true; }
		}
		return false;
	}
};
// 플레이어 객체
player user;


void solution() {
	// input
	// map
	cin >> map.size.x >> map.size.y;
	for (int i = 1; i <= map.size.x; i++) {
		for (int j = 1; j <= map.size.y; j++) {
			cin >> map.objs[i][j];
			switch (map.objs[i][j]) {
			case '&':	map.mobNum++;	break;
			case 'M':	map.mobNum++;	break;
			case 'B':	map.itemNum++;	break;
			case '@':	map.playerStartX = i;	map.playerStartY = j;	break;
			case '^':	map.traps[i][j] = true;	break;
			}
		}
	}

	// 리사이즈
	mobs.resize(map.mobNum);
	items.resize(map.itemNum);

	// player move
	string command;
	cin >> command;

	// mob
	for (auto& mob : mobs) {
		cin >> mob.pos.x >> mob.pos.y;
		cin >> mob.name >> mob.atk >> mob.def >> mob.hp >> mob.exp;

		mob.maxHp = mob.hp;	// 플레이어 부활 시 몬스터도 다시 피 채우기 위한 용도.
		// 보스
		if (map.objs[mob.pos.x][mob.pos.y] == 'M') {
			mob.grade = boss;
			map.bossX = mob.pos.x;
			map.bossY = mob.pos.y;
		}
	}

	// item(box)
	for (auto& item : items) {
		cin >> item.pos.x >> item.pos.y;
		char type;
		cin >> type;
		switch (type)
		{
		case 'W': {
			item.type = weapon;
			cin >> item.atk;
			break;
		}
		case 'A': {
			item.type = armor;
			cin >> item.def;
			break;
		}
		case 'O': {
			item.type = acc;
			string accType;
			cin >> accType;
			if (accType == "HR") { item.accType = HR; }
			else if (accType == "RE") { item.accType = RE; }
			else if (accType == "CO") { item.accType = CO; }
			else if (accType == "EX") { item.accType = EX; }
			else if (accType == "DX") { item.accType = DX; }
			else if (accType == "HU") { item.accType = HU; }
			else if (accType == "CU") { item.accType = CU; }
		}// case
		}// switch
	}

	// 초기화
	user.initPlayer();

	// 게임 시작
	int cSize = (int)command.size();	// 반복문 끝내기용
	int cIdx = 0;	// 다음 커맨드 발동용
	do {
		// 이동
		user.move(command[cIdx++]);
		// 조우
		user.encounter();
		// 털ㄴ업
		map.turn++;

		// 게임 종료 판단
		// 1. 유저 사망 판단: 원인은 battle 혹은 activeTrap에서 기록
		if (user.state == die) { break; }

		// 2. 보스 처치 판단
		if (map.objs[map.bossX][map.bossY] != 'M') {
			map.endCause = win;
			break;
		}

		// 3. 커맨드 종료 판단 (보스 못잡음)
		if (cIdx == (int)command.size()) {
			map.endCause = progress;
			break;
		}

	} while (--cSize);

	// 아웃풋
	for (int x = 1; x <= map.size.x; x++) {
		for (int y = 1; y <= map.size.y; y++) {
			cout << map.objs[x][y];
		}
		cout << '\n';
	}
	cout << "Passed Turns : " << map.turn << '\n';
	cout << "LV : " << user.level << '\n';
	cout << "HP : " << user.hp << '/' << user.maxHp << '\n';
	cout << "ATT : " << user.atk << '+' << user.equippedWeapon.atk << '\n';
	cout << "DEF : " << user.def << '+' << user.equippedArmor.def << '\n';
	cout << "EXP : " << user.exp << '/' << user.level * 5 << '\n';

	switch (map.endCause) {
	case win:
		cout << "YOU WIN!";
		break;
	case progress:
		cout << "Press any key to continue.";
		break;
	case killedByMob:
	case killedByBoss:
	case killedByTrap:
		cout << "YOU HAVE BEEN KILLED BY " << map.killer << "..";
		break;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}