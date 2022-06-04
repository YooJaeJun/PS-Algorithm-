#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1234567;

ll solution(int n) {
    vector<ll> dp(n + 1);
    dp[1] = 1;
    if (n >= 2) dp[2] = 2;
    
    for(int i=3; i<=n; i++)
        dp[i] = (dp[i - 2] + dp[i - 1]) % mod;
    
    return dp[n];
}
