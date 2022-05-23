#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> dic;
    for(auto& cloth : clothes)
    {
        ++dic[cloth[1]];
    }
    
    int ans = 1;
    for(auto& elem : dic)
    {
        ans *= (elem.second + 1);
    }
    return ans - 1;
}