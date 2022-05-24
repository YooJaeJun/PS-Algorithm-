#include <bits/stdc++.h>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    deque<string> dq;
    int cost = 0;
    
    for(auto& city : cities)
    {
        if (cacheSize == 0) cost += 5;
        else
        {
            for(auto& ch : city) // 소문자로 통일
                if (ch >= 'A' && ch <= 'Z')
                    ch += 'a' - 'A';
        
            bool hit = false;
            for(int i=0; i<dq.size(); i++)
            {
                if (dq[i] == city)
                {// 캐시 적중 시 앞으로 보내기
                    dq.push_back(dq[i]);
                    dq.erase(dq.begin() + i);
                    hit = true;
                    cost++;
                    break;
                }
            }
            if (hit == false)
            {
                cost += 5;
                dq.push_back(city);
            }
            
            if (dq.size() > cacheSize)
            {
                dq.pop_front();
            }
        }
    }
    return cost;
}