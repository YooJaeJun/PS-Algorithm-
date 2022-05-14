#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> order(n + 1);
    map<string, bool> dic;
    vector<int> ans = {0, 0};
    string before;
    
    int i = 1;
    for(auto& word : words)
    {
        order[i]++;
        
        if(before == "") before = word;
        else if(before.back() != word.front())
        {
            ans = { i, order[i] };
            break;
        }
        else before = word;
        
        if(dic[word]) 
        {
            ans = { i, order[i] };
            break;
        }
        dic[word] = true;
        
        if(i == n) i = 1;
        else ++i;
    }
    return ans;
}