#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

//정렬용. vector<pair<int, double>>의 first가 키(스테이지 종류), second가 값(실패율)
/*const bool cmp(const pair<int, double> a, const pair<int, double> b) {
	if (a.second == b.second) {
		return a.first < b.first;	//값이 같을 땐 키 오름차순
	}
	return a.second > b.second;
}*/

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	double fail_num = 0;
	double challenge_num = 0;
	unordered_map<int, double> fail_rate;	//<stage idx, 실패율>.
	for (int i = 1; i <= N; i++) {
		//스테이지 1개 도전, 실패 판단
		for (const auto& elem : stages) {
			if (i < elem) {
				challenge_num++;
			}
			else if (i == elem) {
				fail_num++;
				challenge_num++;
			}
		}
		if (challenge_num != 0) {
			fail_rate[i] = fail_num / challenge_num;
		}
		else {
			fail_rate[i] = 0;
		}
		fail_num = 0;
		challenge_num = 0;
	}
	//정렬용
	/*vector<pair<int, double>> sort_rate(fail_rate.begin(), fail_rate.end());
	sort(sort_rate.begin(), sort_rate.end(), cmp);
	for (const auto& elem : sort_rate) {
		answer.push_back(elem.first);
	}*/
	vector<double> sort_rate;
	for (int i = 1; i <= N; i++) {
		sort_rate.push_back(fail_rate[i]);
	}
	sort(sort_rate.begin(), sort_rate.end(), greater<double>());
	for (int i = 0; i != sort_rate.size(); i++) {
		for (int j = 1; j <= fail_rate.size(); j++) {
			if (sort_rate[i] == fail_rate[j]) {
				answer.push_back(j);
				fail_rate[j] = -1;	//값 발견하면 키 가져오고 값 무효화(중복 경우 대비)
			}
		} 
	}
	return answer;
}