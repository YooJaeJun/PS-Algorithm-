#include <iostream>
#include <deque>
#include <functional>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	deque<int> dq[4];
	string input;

	for (int i = 0; i < 4; i++)
	{
		cin >> input;

		for (int j = 0; j < 8; j++)
			dq[i].push_back(input[j] - '0');
	}

	int k;
	cin >> k;
	int index = 0, direction = 0;

	auto RotateDetail = [&](int dir, int idx)
	{
		if (dir == 1)
		{
			dq[idx].push_front(dq[idx].back());
			dq[idx].pop_back();
		}
		else
		{
			dq[idx].push_back(dq[idx].front());
			dq[idx].pop_front();
		}
	};

	function<void(int, int)> RotateLeft = [&](int dir, int idx)
	{
		if (idx > 0 &&
			dq[idx][6] != dq[idx - 1][2])
			RotateLeft(dir * -1, idx - 1);

		RotateDetail(dir, idx);
	};

	function<void(int, int)> RotateRight = [&](int dir, int idx)
	{
		if (idx < 3 &&
			dq[idx][2] != dq[idx + 1][6])
			RotateRight(dir * -1, idx + 1);

		RotateDetail(dir, idx);
	};

	while(k--)
	{
		cin >> index >> direction;
		index--;

		// Left
		if (index > 0 &&
			dq[index][6] != dq[index - 1][2])
			RotateLeft(direction * -1, index - 1);
		// Right
		if (index < 3 &&
			dq[index][2] != dq[index + 1][6])
			RotateRight(direction * -1, index + 1);

		RotateDetail(direction, index);
	}

	int factor = 1, sum = 0;

	for (int i=0; i<4; i++)
	{
		if (dq[i][0] == 1)
			sum += factor;
		factor *= 2;
	}

	cout << sum;

	return 0;
}