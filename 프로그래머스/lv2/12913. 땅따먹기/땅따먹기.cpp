#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    vector<vector<int>> dp(land.size(), vector<int>(4));
    int answer = 0;

    // 초기값
    for (int i = 0; i != 4; i++) {
        dp[0][i] = land[0][i];
    }

    for (int i = 1; i != land.size(); i++) {
        for (int j = 0; j != 4; j++) {
            int maxDpBefore = 0;
            for (int k = 0; k != 4; k++) {
                if (j != k) {
                    maxDpBefore = max(maxDpBefore, dp[i - 1][k]);
                }
            }
            dp[i][j] = max(dp[i][j], maxDpBefore) + land[i][j];
        }
    }

    answer = *max_element(dp[land.size() - 1].begin(), dp[land.size() - 1].end());

    return answer;
}