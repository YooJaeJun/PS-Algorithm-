#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		float distSq = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

		auto Square = [&](const int n){	return n * n; };

		// 완전 동일
		if (x1 == x2 && y1 == y2 && r1 == r2)
			cout << -1 << '\n';
		// 두 점
		else if (distSq > Square(r1 - r2) &&
			distSq < Square(r1 + r2))
			cout << 2 << '\n';
		// 한 점 외접 & 내접
		else if (distSq == Square(r1 + r2) ||
			distSq == Square(r1 - r2))
			cout << 1 << '\n';
		// 만나지 않음
		else if (distSq > Square(r1 + r2) ||
			distSq < Square(r1 - r2) || 
			distSq == 0)
			cout << 0 << '\n';
	}

	return 0;
}