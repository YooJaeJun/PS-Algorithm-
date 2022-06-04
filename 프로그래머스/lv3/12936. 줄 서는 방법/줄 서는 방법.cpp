#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fac[21]{ 0, };
vector<int> ans, candidate; // candidate: ans에 넣을 1~n 까지 수들

void updateFactorial(int end)
{
    fac[1] = 1;
    for (int i = 2; i <= end; i++)
        fac[i] = fac[i - 1] * i;
}

void search(int n, ll k)
{
    if (n == 1)
    {
        ans.push_back(candidate.back());
        return;
    }
    ll order = k / fac[n - 1] + 1;
    ans.push_back(candidate[order]);
    candidate.erase(candidate.begin() + order);
    search(n - 1, k % fac[n - 1]);
}

vector<int> solution(int n, long long k) {
    updateFactorial(n);

    candidate.resize(n + 1);
    for (int i = 1; i <= n; i++) candidate[i] = i;

    search(n, k - 1);

    return ans;
}