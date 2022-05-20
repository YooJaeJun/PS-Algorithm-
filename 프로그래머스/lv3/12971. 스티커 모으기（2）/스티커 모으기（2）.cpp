#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> sticker)
{
    int n = sticker.size();
    vector<int> dp1(n), dp2(n);   // 첨 스티커 뗌, 마지막 스티커 뗌
    dp1[0] = sticker[0];
    dp2[0] = 0;
    int ans = dp1[0];
    
    if (n >= 2)
    {
        dp1[1] = dp2[1] = sticker[1];
        ans = max(ans, dp1[1]);
    }
    if (n >= 3)
    {
        dp1[2] = sticker[2] + sticker[0];
        dp2[2] = sticker[2];
        ans = max(ans, dp1[2]);
    }
    
    for(int i=3; i<n; i++)
    {
        if (i == n - 1) {}
        else dp1[i] = max(dp1[i - 2], dp1[i - 3]) + sticker[i];
        
        if (i == 3) dp2[i] = dp2[i - 2] + sticker[i];
        else dp2[i] = max(dp2[i - 2], dp2[i - 3]) + sticker[i];
        
        ans = max(ans, max(dp1[i], dp2[i]));
    }
    
    return ans;
}