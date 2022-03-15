#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<string> dayweak { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };		//n%7==0이 될 수 있기에 앞에 SUN.
	vector<int> monthlydays{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };	//1월은 보정 없으며, 12월 월일은 상관 없어서 안 넣음.
	int x, y;
	string answer;
	scanf("%d %d", &x, &y);
	//y(+?) % 7 번째의 dayweak의 원소
	//(+?) : 30일이면 다음달 +3, 28일이면 다음달 +0, 30일이면 다음달 +2(== monthlydays[x] % 7)로 규칙 파악
	int coef = 0;
	for (int i = 1; i != x; i++) {
		coef += monthlydays[i] % 7;
	}
	answer = dayweak[(y + coef) % 7];
	cout << answer;
	return 0;
}