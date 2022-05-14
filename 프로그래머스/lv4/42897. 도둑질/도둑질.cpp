#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> money) {
    vector<int> dp1(money.size());
    vector<int> dp2(money.size());
    dp1[0] = money[0];
    dp1[1] = dp2[1] = money[1];
    dp1[2] = money[0] + money[2];
    dp2[2] = money[2];
    
    int ans = 0;
    ans = max(ans, dp1[1]);
    ans = max(ans, max(dp1[2], dp2[2]));
    
    for(int i=3; i<money.size(); ++i)
    {
        if(i != money.size() - 1)
        {
            dp1[i] = max(dp1[i - 2], dp1[i - 3]) + money[i];
        }
        dp2[i] = max(dp2[i - 2], dp2[i - 3]) + money[i];
        
        ans = max(ans, max(dp1[i], dp2[i]));
    }
    
    return ans;
}