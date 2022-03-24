#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int test = 1;

vector<vector<char>> grid;

struct coord {
	int x, y;
};

struct unit {
	coord pos;
	unit(int x, int y) : pos({ x, y }) {}
};

struct box : public unit {
	box(int x, int y) : unit({ x, y }) {}
};
vector<box> boxes;

struct target : public unit {
	target(int x, int y) : unit({ x, y }) {}
};
vector<target> targets;

struct character : public unit {
	character(int x, int y) : unit({ x, y }) {}
};
character player(0, 0);


enum eMovableState {
	invalid, inTarget, inEmpty, unconfirmed
};



void changePriorPos(int x, int y) {
	switch (grid[x][y]) {
	case 'W':
	case 'B':
		grid[x][y] = '+';
		break;
	case 'w':
	case 'b':
		grid[x][y] = '.';
		break;
	}
}

int isBoxMovable(int nx, int ny) {
	switch (grid[nx][ny]) {
	case '#':
	case 'b':
	case 'B':
		return invalid;

	case '+':
		return inTarget;

	case '.':
		return inEmpty;
	}

	return invalid;
}

int isPlayerMovable(int nx, int ny, char command) {
	switch (grid[nx][ny]) {
	case '.':
		return inEmpty;

	case '+':
		return inTarget;

	case '#':
		return invalid;

	case 'b':
	case 'B': {
		int boxIdx = -1;
		for (int i = 0; i != boxes.size(); i++) {
			if (boxes[i].pos.x == nx &&
				boxes[i].pos.y == ny) {
				boxIdx = i;
				break;
			}
		}

		switch (command) {
		case 'U':	nx--;	break;
		case 'D':	nx++;	break;
		case 'R':	ny++;	break;
		case 'L':	ny--;	break;
		}//switch

		int movable = isBoxMovable(nx, ny);
		switch (movable) {
		case invalid:
			break;
		case inTarget:
		case inEmpty:
			// 이동 전 좌표 표시 변경 (B or b에 따라 + or .)
			changePriorPos(boxes[boxIdx].pos.x, boxes[boxIdx].pos.y);

			// '+'인지, '.'인지 캐릭터에게 던져줄 거임
			char beforeChar = grid[boxes[boxIdx].pos.x][boxes[boxIdx].pos.y];

			boxes[boxIdx].pos.x = nx;
			boxes[boxIdx].pos.y = ny;

			if (movable == inTarget) { 
				grid[nx][ny] = 'B';	// 대문자
			}	
			else if (movable == inEmpty) { 
				grid[nx][ny] = 'b';	// 소문자
			}

			// 캐릭터에게 던져줌
			if (beforeChar == '+') {
				return inTarget;
			}
			else if (beforeChar == '.') {
				return inEmpty;
			}
		}

		break;
	}//case
	}//switch

	return invalid;
}

void moveCharacter(char command) {
	int nx = player.pos.x, ny = player.pos.y;
	switch (command) {
	case 'U':	nx = player.pos.x - 1;	break;
	case 'D':	nx = player.pos.x + 1;	break;
	case 'R':	ny = player.pos.y + 1;	break;
	case 'L':	ny = player.pos.y - 1;	break;
	}

	int movable = isPlayerMovable(nx, ny, command);
	switch (movable)
	{
	case invalid:
		break;
	case inTarget:
	case inEmpty:
	case unconfirmed:
		// 이동 전 좌표 표시 변경 (W or w에 따라 + or .)
		changePriorPos(player.pos.x, player.pos.y);
		// 이동
		player.pos.x = nx;
		player.pos.y = ny;

		if (movable == inTarget) { 
			grid[nx][ny] = 'W';	// 대문자
		}
		else if (movable == inEmpty) { 
			grid[nx][ny] = 'w'; // 소문자
		}
		else if (movable == unconfirmed) {

			grid[nx][ny] = 'W';	// 대문자
		}
		break;
	}
}

bool isSuccess(int testIdx) {
	int success = 0;
	for (int i = 0; i != boxes.size(); i++) {
		if (grid[boxes[i].pos.x][boxes[i].pos.y] == 'b') {
			return false;
		}
	}
	return true;
}

void solution() {
	int x, y;
	cin >> x >> y;
	for (int testIdx = 1; ; testIdx++) {
		// 매 테케마다 초기화
		grid.resize(x + 1);
		for (int i = 1; i < (int)grid.size(); i++) {
			grid[i].resize(y + 1, '0');
		}
		boxes.clear();
		targets.clear();

		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				cin >> grid[i][j];
				switch (grid[i][j]) {
				case 'w':
				case 'W':
					player.pos.x = i;
					player.pos.y = j;
					break;
				case 'b':
				case 'B':
					boxes.push_back(box(i, j));
					break;
				case '+':
					targets.push_back(target(i, j));
					break;
				}
			}
		}

		string commands;
		cin >> commands;

		for (auto& command : commands) {

			moveCharacter(command);

			test++;

			if (isSuccess(testIdx)) {
				break;
			}
		}

		cout << "Game " << testIdx << ": ";
		if (isSuccess(testIdx)) {
			cout << "complete" << '\n';
		}
		else {
			cout << "incomplete" << '\n';
		}

		for (int i = 1; i < grid.size(); i++) {
			for (int j = 1; j < grid[i].size(); j++) {
				cout << grid[i][j];
			}
			cout << '\n';
		}


		cin >> x >> y;
		if (x == 0 && y == 0) {
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}