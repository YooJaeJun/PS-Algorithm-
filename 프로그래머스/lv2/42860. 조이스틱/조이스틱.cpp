#include <bits/stdc++.h>
using namespace std;

int solution(string name) {
    int ans = 0;
    int move = name.size() - 1;
    
    for(int i=0; i<name.size(); i++)
    {
        ans += min(name[i] - 'A', 'Z' - name[i] + 1);
        
        int next = i + 1;   // 다음 'A' 안 나오는 지점
        while(next < name.size() and name[next] == 'A')
            next++;
        
        move = min(move, i * 2 + (int)name.size() - next);   // 앞->뒤
        move = min(move, ((int)name.size() - next) * 2 + i);  // 뒤->앞
    }
    return ans + move;
}