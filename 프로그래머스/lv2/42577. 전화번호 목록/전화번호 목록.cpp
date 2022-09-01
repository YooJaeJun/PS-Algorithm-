#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
    map<string, int> dic;
    for(auto& number : phone_book) dic[number]++;
    
    string s1, s2;
    int minSize;
    auto endBefore = --dic.end();
    for(auto it = dic.begin(); it != endBefore; )
    {
        s1 = it++->first;
        s2 = it->first;
        minSize = min(s1.size(), s2.size());
        if (s1.substr(0, minSize) == s2.substr(0, minSize))
        {
            return false;
        }
    }
    return true;
}