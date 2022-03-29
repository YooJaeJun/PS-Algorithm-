#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> dp(n + 1, 0);  // 가로 길이
    const int inf = 1e9 + 7;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % inf;
    }

    return dp[n];
}