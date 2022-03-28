#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> day;

	//작업일 구하기
	for (int i = 0; i != progresses.size(); i++) {
		if ((100 - progresses.at(i)) % speeds.at(i) != 0) {
			day.push_back(((100 - progresses.at(i)) / speeds.at(i)) + 1);
		}
		else {
			day.push_back(((100 - progresses.at(i)) / speeds.at(i)));
		}
	}

	size_t idx = 0;
	size_t i = 1;
	for (; i != day.size();++i) {
		if (day[idx] < day[i]) {
			answer.push_back(i - idx);
			idx = i;
		}
	}

	answer.push_back(i - idx);
	return answer;
}