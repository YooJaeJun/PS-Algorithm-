#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template<typename T>
class Queue
{
public:
	inline int Size() const { return q.size(); }
	inline int Empty() const { return q.empty(); }
	T Front() const
	{
		if (q.empty())
			return -1;
		return q.front();
	}
	T Back() const
	{
		if (q.empty())
			return -1;
		return q.back();
	}
	void Push(const int x)
	{
		q.push(x);
	}
	T Pop()
	{
		if (q.empty())
			return -1;
		T ret = q.front();
		q.pop();
		return ret;
	}

private:
	queue<T> q;
};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	Queue<int> q;
	int n;
	cin >> n;

	while (n--)
	{
		string input;
		cin >> input;
		if (input == "push")
		{
			int x;
			cin >> x;
			q.Push(x);
		}
		else if (input == "pop")
			cout << q.Pop() << '\n';
		else if (input == "size")
			cout << q.Size() << '\n';
		else if (input == "empty")
			cout << q.Empty() << '\n';
		else if (input == "front")
			cout << q.Front() << '\n';
		else if (input == "back")
			cout << q.Back() << '\n';
	}

	return 0;
}