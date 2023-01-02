#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> topping) {
    unordered_map<int, int> dic1, dic2;
    dic1[topping[0]]++;
    
    int size = topping.size();
    for (int i=1; i<size; i++)
    {
        dic2[topping[i]]++;
    }
    
    int answer = 0;
    if (dic1.size() == dic2.size()) answer++;
    
    for (int i=1; i<size; i++)
    {
        dic1[topping[i]]++;
        dic2[topping[i]]--;
        if (dic2[topping[i]] == 0) dic2.erase(topping[i]);
        if (dic1.size() == dic2.size()) answer++;
    }
    
    return answer;
}