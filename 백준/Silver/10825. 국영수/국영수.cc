#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;


struct score {
	string name;
	int korean, english, math;
	bool operator<(const score &s2) const {
		if (korean > s2.korean) return 1;
		else if (korean < s2.korean) return 0;
		
		if (english < s2.english) return 1;
		else if (english > s2.english) return 0;
		
		if (math > s2.math) return 1;
		else if (math < s2.math) return 0;
		
		if (name < s2.name) return 1;
		else if (name > s2.name) return 0;

		return 0;
	}
};

bool compare(score s1, score s2) {
	return s1 < s2;
}

void solution() {
	int n;
	cin >> n;
	vector<score> v;
	for (int i = 0; i != n; i++) {
		string name;
		int korean, english, math;
		cin >> name >> korean >> english >> math;
		v.push_back({ name, korean, english, math });
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i != n; i++) {
		cout << v[i].name << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) { solution(); }
	return 0;
}