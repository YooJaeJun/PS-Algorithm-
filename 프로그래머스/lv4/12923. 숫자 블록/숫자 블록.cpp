#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> solution(long long begin, long long end) {
    ll maxn = 10'000'000;
    vector<int> answer(end - begin + 1);
    for (ll i = begin; i <= end; i++)
    {
        if (i == 1) answer[i - begin] = 0;
        else answer[i - begin] = 1;
        
        for (ll j = max((ll)2, i / maxn); j * j <= i; j++)
        {
            ll share = i / j;
            if (i % j == 0 && share <= maxn)
            {
                answer[i - begin] = share;
                break;
            }
        }
    }
    return answer;
}