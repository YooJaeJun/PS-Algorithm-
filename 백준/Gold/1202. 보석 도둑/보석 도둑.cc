#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct jewelry {
	ll weight, price;
	bool operator<(jewelry j) {
		return weight < j.weight;
	}
};

void solution() {
	int n, k;
	cin >> n >> k;
	vector<jewelry> mv(n);
	for (int i = 0; i != n; i++) {
		cin >> mv[i].weight >> mv[i].price;
	}

	vector<ll> bags(k);
	for (int i = 0; i != k; i++) {
		cin >> bags[i];
	}

	sort(mv.begin(), mv.end());
	sort(bags.begin(), bags.end());

	int idx = 0;
	priority_queue<ll> pq;
	ll ans = 0;
	for (auto& bag : bags) {
		for (int i = idx; i != n; i++, idx++) {
			if (bag >= mv[i].weight) {
				pq.push(mv[i].price);
			}
			else {
				break;
			}
		}
		if (pq.empty() == false) {
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testCaseNum = 1;
	// cin >> testCaseNum;
	for (int i = 0; i != testCaseNum; i++) { solution(); }
	return 0;
}