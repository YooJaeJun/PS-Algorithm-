#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    int n = s.size();
    vector<int> memo(27), ans;
    
    for (int i=1; i<=n; i++)
    {
        if (memo[s[i - 1] - 'a' + 1])
        {
            ans.emplace_back(i - memo[s[i - 1] - 'a' + 1]);
        }
        else 
        {
            ans.emplace_back(-1);
        }
        memo[s[i - 1] - 'a' + 1] = i;
    }
    
    return ans;
}