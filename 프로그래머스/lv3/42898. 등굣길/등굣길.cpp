#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[1][1] = 1;
    const int inf = 1e9 + 7;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) { continue; }

            bool isPuddle = false;
            for (auto& elem : puddles) {
                if (elem[1] == i && elem[0] == j) {
                    isPuddle = true;
                    break;
                }
            }
            if (isPuddle) { continue; }

            dp[i][j] = (dp[i - 1][j] % inf + dp[i][j - 1] % inf) % inf;
        }
    }
    return dp[n][m];
}