#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
    int n = s.size();
    deque<deque<bool>> dp(n + 1, deque<bool>(n));
    int ans = 1;
    // place: 자릿수, idx: 인덱스
    for(int place=1; place<=n; place++)
    {
        for(int idx=0; idx<n; idx++)
        {
            if (place == 1) dp[place][idx] = true;
            else if (place == 2 and s[idx] == s[idx + 1]) 
            {
                dp[place][idx] = true;
                ans = 2;
            }
            else if (dp[place - 2][idx + 1] and     // -2 자릿수 다음 idx dp가 true면
                     s[idx] == s[idx + place - 1])  // 시작과 끝이 같으면
            {
                dp[place][idx] = true;
                ans = place;
            }
        }
    }
    return ans;
}