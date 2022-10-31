#include <string>
#include <vector>
#include <functional>

using namespace std;

int solution(int balls, int share) {
    vector<vector<int>> dp(balls + 1, vector<int>(balls + 1));
    
    function<int(int, int)> combi = [&](int n, int r)
    {
        if (r == 0) return 1;
        else if (n == 1) return 1;
        else if (r >= n) return 1;
        else if (dp[n][r]) return dp[n][r];
        return dp[n][r] = combi(n-1, r) + combi(n-1, r-1);
    };
    return combi(balls, share);
}