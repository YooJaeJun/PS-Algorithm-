#include <string>
#include <vector>

using namespace std;

vector<int> dp;
int answer = 1e9;

void Recur(int x, const int y, const int n, int count)
{
    if (x >= y)
    {
        if (x == y)
        {
            dp[x] = count;
            answer = min(answer, dp[x]);
        }
        return;
    }
    else if (dp[x] && dp[x] <= count)
        return;
    
    dp[x] = count;
    
    Recur(x + n, y, n, count + 1);
    Recur(x * 2, y, n, count + 1);
    Recur(x * 3, y, n, count + 1);
}

int solution(int x, int y, int n) {
    dp.resize(y + 1);
    
    Recur(x, y, n, 0);
    
    return answer == 1e9? -1 : answer;
}