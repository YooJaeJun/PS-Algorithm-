#include <bits/stdc++.h>
using namespace std;

int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> dic;
    for (auto& elem : tangerine)
    {
        dic[elem]++;
    }
    
    vector<int> sorted;
    for (auto& elem : dic)
    {
        sorted.push_back(elem.second);
    }
    
    sort(sorted.begin(), sorted.end(), greater<int>());
    
    int cur = k;
    int ans = 0;
    for (auto& elem : sorted)
    {
        if (cur >= elem)
        {
            cur -= elem;
            ans++;
        }
        else if (cur != 0)
        {
            cur = 0;
            ans++;
        }
    }
    return ans;
}