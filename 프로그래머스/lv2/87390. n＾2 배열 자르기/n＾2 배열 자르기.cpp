#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long i=left; i<=right; i++)
    {
        int first = i / n + 1;
        int second = i % n;
        
        if (second < first)
            answer.push_back(first);
        else
            answer.push_back(second + 1);
    }
    
    return answer;
}