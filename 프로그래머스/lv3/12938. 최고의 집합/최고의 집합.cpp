#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, int s) {
    if (s < n) return {-1};
    
    vector<int> answer(n);
    int share = s / n;
    for (auto& elem : answer) elem = share;
    
    int remain = s % n;
    for (int i=n-1; i>=0 && remain > 0; i--)
    {
        answer[i]++;
        remain--;
    }
    
    return answer;
}