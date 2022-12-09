#include <bits/stdc++.h>
using namespace std;

int solution(int k, int m, vector<int> score) {
    sort(score.begin(), score.end(), greater<int>());
    int ans = 0;
    
    for (int i=0; i<score.size(); i += m)
    {
        if (i + m - 1 < score.size())
        {
            ans += score[i + m - 1] * m;
        }
    }
    
    return ans;
}