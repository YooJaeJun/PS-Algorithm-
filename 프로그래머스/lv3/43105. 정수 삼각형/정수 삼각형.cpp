#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> dp(triangle.size());
    dp[0].emplace_back(triangle[0][0]);
    int ans = 0;
    
    for (int i=1; i<triangle.size(); i++)
    {
        dp[i].resize(triangle[i].size());
        
        for (int j=0; j<=i; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j];
            else if (j == i)
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
            
            dp[i][j] += triangle[i][j];
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}