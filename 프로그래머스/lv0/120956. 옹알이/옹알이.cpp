#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> vs = { "aya", "ye", "woo", "ma" };
    
    for (auto str : babbling)
    {
        string prev;
        bool flag = false;
        for (int i=0; i < str.size(); )
        {
            for (int j=0; j<4; j++)
            {
                flag = false;
                if (prev != vs[j] && 
                    str[i] == vs[j][0] && 
                    str.substr(i, vs[j].size()) == vs[j])
                {
                    prev = vs[j];
                    i += vs[j].size();
                    flag = true;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag) answer++;
    }
    
    return answer;
}