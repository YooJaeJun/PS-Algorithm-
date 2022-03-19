#include <iostream>
#include <vector>
using namespace std;

int cross(pair<int, int>& p1, pair<int, int>& p2, pair<int, int>& p3) {
	return p1.first * p2.second - p2.first * p1.second +
		p2.first * p3.second - p3.first * p2.second +
		p3.first * p1.second - p1.first * p3.second;
}

void solution() {
	pair<int, int> p1, p2, p3;
	cin >> p1.first >> p1.second;
	cin >> p2.first >> p2.second;
	cin >> p3.first >> p3.second;

	if (cross(p1, p2, p3) == 0) { cout << 0; }
	else if (cross(p1, p2, p3) < 0) { cout << -1; }
	else { cout << 1; }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}