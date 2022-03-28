#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;

	//lottos와 win_nums 간 같은 것 찾기
	size_t min = 0;
	for (size_t i : win_nums) {
		auto it = find(lottos.begin(), lottos.end(), i);
		if (it != lottos.end()) {
			min++;
		}
	}

	//0 개수 구하기
	size_t zero_num = 0;
	for (size_t i : lottos) {
		if (i == 0) {
			zero_num++;
		}
	}

	//순위 구하기
	size_t max = min + zero_num;
	size_t rank[] = { 6,6,5,4,3,2,1 };
	answer.push_back(rank[max]);
	answer.push_back(rank[min]);

	return answer;
}


//find 안쓴 버전, for(T i : v) 안 쓴 버전
/*
	for (int i = 0; i != 6; i++) {
		idx = 0;
		while (idx != 6) {
			if (win_nums[i] == lottos[idx]) {
				min++;
				break;
			}
			idx++;
		}
	}
*/