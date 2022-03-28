#include <string>
#include <vector>
#include <map>
using namespace std;

//특수기호로 문자열 split한 user 리턴. //sstream 안 쓰고 써보는 함수
const vector<string> split(const string str, const char sign) {
	vector<string> ret;
	string tmp;
	int sign_point = 0;
	for (int i = 0; i != 3; i++) {	//act, uid, name 총 3회
		if (sign_point >= str.size()) { break; }	//문자열 끝에서 탈출
		if (i == 0) {	//최초엔 0부터 순회
			for (int j = 0; str[j] != sign; j++) {
				tmp += str[j];
				sign_point = j + 1;
			}
		}
		else {
			for (int j = sign_point + 1; str[j] != sign; j++) {	//구분기호의 다음 칸부터 순회
				tmp += str[j];
				sign_point = j + 1;
				if (sign_point >= str.size()) { break; }	//문자열 끝이면 탈출
			}
		}
		switch (i)
		{
		case 0: ret.push_back(tmp); break;	//act
		case 1: ret.push_back(tmp); break;	//uid
		case 2: ret.push_back(tmp); break;	//name *Leave는 없음
		}
		tmp.clear();
	}
	return ret;
}
vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> users;
	vector<string> tmp;	//split한 문자열들 받을 용도
	string act, uid, name;
	for (int i = 0; i != record.size(); i++) {
		//유저 정보 split해서 넣기
		tmp = split(record[i], ' ');
		act = tmp[0];
		uid = tmp[1];
		if (act == "Enter" || act == "Change") {
			name = tmp[2];
			users[uid] = name;
		}
	}
	for (int i = 0; i != record.size(); i++) {
		tmp = split(record[i], ' ');
		act = tmp[0];
		uid = tmp[1];
		if (act == "Enter") {
			answer.push_back(users[uid] + "님이 들어왔습니다.");
		}
		else if (act == "Leave") {
			answer.push_back(users[uid] + "님이 나갔습니다.");
		}
	}
	return answer;
}