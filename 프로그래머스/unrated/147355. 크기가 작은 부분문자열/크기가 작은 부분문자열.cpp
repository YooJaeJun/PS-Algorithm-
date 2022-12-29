#include <bits/stdc++.h>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long long b = stoll(p);
    int size = t.size() - p.size() + 1;
    
    for (int i=0; i<size; i++)
    {
        if (t[i] > p[0]) continue;
        long long a = stoll(t.substr(i, p.size()));
        if (a <= b) answer++;
    }
    
    return answer;
}