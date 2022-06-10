#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using db = deque<bool>;
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define forn(i, n) for (int i = 0; i < (int)n; i++)
const int maxn = 1e9 + 7;
const double mod = 1e9 + 7;


int n;

void recurLine(int cnt)
{
	forn(i, cnt) cout << "_";
}

void recur1(int cnt)
{
	if (cnt == 0) return;
	recur1(cnt - 1);
	recurLine(cnt * 4 - 4);
	cout << "\"재귀함수가 뭔가요?\"" << '\n';
	recurLine(cnt * 4 - 4);
	cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << '\n';
	recurLine(cnt * 4 - 4);
	cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << '\n';
	recurLine(cnt * 4 - 4);
	cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << '\n';
}

void bridge()
{
	recurLine(n * 4);
	cout << "\"재귀함수가 뭔가요?\"" << '\n';
	recurLine(n * 4);
	cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << '\n';
}

void recur2(int cnt)
{
	if (cnt == -1) return;
	recur2(cnt - 1);
	recurLine((n - cnt) * 4);
	cout << "라고 답변하였지." << '\n';
}

void solution()
{
	cin >> n;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << '\n';

	recur1(n);
	bridge();
	recur2(n);
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 0; i != t; i++) solution();
	return 0;
}