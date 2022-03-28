#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
	int answer = 123456789;
	int sum = 0;
	for (int i; i != absolutes.size(); i++) {
		if (!signs[i]) {
			absolutes[i] = -absolutes[i];	//음수
		}
		sum += absolutes[i];
	}
	answer = sum;
	return answer;
}