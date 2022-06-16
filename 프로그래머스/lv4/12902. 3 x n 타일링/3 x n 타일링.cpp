#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solution(int n) {
    const ll mod = 1'000'000'007;
    vector<ll> dp(n + 1);
    dp[2] = 3;
    dp[4] = 11; // dp[1] * dp[1] + 2
    
    for(int i = 6; i <= n; i += 2)
    {
        dp[i] += dp[i - 2] * dp[2] + 2;
        
        for(int j = i - 4; j >= 2; j -= 2)
        {
            dp[i] += dp[j] * 2;
        }
        dp[i] %= mod;
    }
    
    return dp[n];
}