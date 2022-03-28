#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
	//answers.size()만큼 각 패턴의 값 넣기
	vector<int> a, b, c;
	vector<int> b_pattern = { 2, 1, 2, 3, 2, 4, 2, 5 };
	vector<int> c_pattern = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	int a_elem = 1, b_elem = 0, c_elem = 0;
	for (int i = 0; i != answers.size(); i++) {
		a.push_back(a_elem++);
		if (a_elem > 5) { a_elem = 1; }

		if (b_elem >= b_pattern.size()) { b_elem = 0; }
		b.push_back(b_pattern[b_elem++]);

		if (c_elem >= c_pattern.size()) { c_elem = 0; }
		c.push_back(c_pattern[c_elem++]);
	}
	//정답 체크
	vector<int> right = { 0, 0, 0 };
	for (int i = 0; i != answers.size(); i++) {
		if (a[i] == answers[i]) { right[0]++; }
		if (b[i] == answers[i]) { right[1]++; }
		if (c[i] == answers[i]) { right[2]++; }
	}
	//최대값 비교
	int max = *max_element(right.begin(), right.end());
	vector<int> answer;
	for (int i = 0; i != right.size(); i++) {
		if (max <= right[i]) {
			answer.push_back(i + 1);
		}
	}
	return answer;
}