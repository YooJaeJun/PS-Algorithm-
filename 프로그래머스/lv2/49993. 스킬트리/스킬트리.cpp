#include <bits/stdc++.h>
using namespace std;
// #define int int64_t
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;


int solution(string skill, vector<string> skill_trees) {
	vi parent(300);	// 아스키 코드만큼
	int root = 0;
	parent[skill[0]] = root;

	for (int i = 1; i != skill.size(); i++) {
		parent[skill[i]] = skill[i - 1];
	}

	int answer = 0;
	vi learned(300);

	for (auto& tree : skill_trees) {
		fill(learned.begin(), learned.end(), false);
		learned[root] = true;
		bool flag = true;

		for (int i = 0; i != tree.size(); i++) {
			if (learned[parent[tree[i]]] == false) {
				flag = false;
				break;
			}
			learned[tree[i]] = true;
		}
		if (flag) answer++;
	}

	return answer;
}