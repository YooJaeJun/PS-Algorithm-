#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void bfs(const int& start, vector<vector<int>>& nodes, vector<int>& areas, vector<bool>& checked) {
	queue<int> q;
	q.push(start);
	checked[start] = true;
	areas.push_back(1);	//각 영역 최초 1세팅
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < nodes[x].size(); ++i) {
			long unsigned int y = nodes[x][i];	//노드 안의 연결된 노드들
			if (!checked[y]) {
				q.push(y);
				checked[y] = true;
				areas.back()++;
			}
		}
	}
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	vector<vector<int>> nodes;
	vector<int> areas;
	vector<bool> checked;
	vector<vector<int>> piccopy;
	nodes.resize(m * n + 1);
	for (int y = 0; y != m; y++) {	//노드에 연결된 노드들 넣기
		for (int x = 0; x != n; x++) {
			if (x < n - 1 && picture[y][x] != 0 && picture[y][x] == picture[y][x + 1]) {
				nodes[y * n + x + 1].push_back(y * n + x + 2);
				nodes[y * n + x + 2].push_back(y * n + x + 1);
			}
			if (y < m - 1 && picture[y][x] != 0 && picture[y][x] == picture[y + 1][x]) {
				nodes[y * n + x + 1].push_back(y * n + x + 1 + n);
				nodes[y * n + x + 1 + n].push_back(y * n + x + 1);
			}
		}
	}
	piccopy = picture;	//picture 원본을 건드리면 안된다고 함.
	checked.resize(m * n + 1, false);
	int start;
	int idx = 0;
	for (int y = 0; y != m; y++) {	//
		for (int x = 0; x != n; x++) {
			if (!checked[y * n + x + 1] && piccopy[y][x] != 0) {
				start = y * n + x + 1;
				bfs(start, nodes, areas, checked);	//bfs
			}
			if (checked[y * n + x + 1]) {
				piccopy[y][x] = 0;	//체크했으면 picture의 0과 같은 처리
			}
		}
	}
	int number_of_area = areas.size();
	int max_size_of_one_area = *max_element(areas.begin(), areas.end());
	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}