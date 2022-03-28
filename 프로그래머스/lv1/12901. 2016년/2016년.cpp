#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
	vector<string> dayweak{ "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };		//n%7==0이 될 수 있기에 앞에 SUN.
	vector<int> monthlydays{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 };	//1월은 보정 없으며, 12월 월일은 상관 없어서 안 넣음.

	//y(+?) % 7 번째의 dayweak의 원소
	//(+?) : 30일이면 다음달 +3, 28일이면 다음달 +0, 30일이면 다음달 +2(== monthlydays[x] % 7)로 규칙 파악
	//1월 1일 금요일
	int coef = 4;
	for (int i = 1; i != a; i++) {
		coef += monthlydays[i] % 7;
	}
	answer = dayweak[(b + coef) % 7];
    return answer;
}