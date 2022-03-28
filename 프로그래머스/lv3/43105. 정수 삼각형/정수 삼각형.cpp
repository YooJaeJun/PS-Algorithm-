#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int memo[501][501];

int dp(vector<vector<int>>& triangle, int x, int y) {
    if (memo[x][y] != 0) {
        return memo[x][y];
    }
    if (x == 0 || y == 0) {
        return 0;
    }
    if (x < y) {
        return 0;
    }

    // 최초
    if (x == 1 && y == 1) {
        memo[x][y] += dp(triangle, x - 1, y - 1) + triangle[x - 1][y - 1];
    }
    // 마지막 열
    else if (x == y) {
        memo[x][y] += dp(triangle, x - 1, y - 1) + triangle[x - 1][y - 1];
    }
    // 첫 열
    else if (y == 1) {
        memo[x][y] += dp(triangle, x - 1, 1) + triangle[x - 1][0];
    }
    // 그 외
    else {
        memo[x][y] += max(dp(triangle, x - 1, y), dp(triangle, x - 1, y - 1)) + 
            triangle[x - 1][y - 1];
    }

    return memo[x][y];
}

int solution(vector<vector<int>> triangle) {
    vector<int> anss(triangle.size());
    for (int i = 1; i <= triangle.size(); i++) {
        anss.push_back(dp(triangle, triangle.size(), i));
    }
    return *max_element(anss.begin(), anss.end());
}