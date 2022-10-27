#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 = 0, sum2 = 0;
    queue<int> q1, q2;
    for (auto& elem : queue1) 
    {
        sum1 += elem;
        q1.push(elem);
    }
    for (auto& elem : queue2) 
    {
        sum2 += elem;
        q2.push(elem);
    }
    long long ans = 0;
    
    int t = max(q1.size(), q2.size()) * 3;
    while (t--)
    {
        if (sum1 == sum2) return ans;
        else if (sum1 < sum2)
        {
            q1.push(q2.front());
            q2.pop();
            sum1 += q1.back();
            sum2 -= q1.back();
            ans++;
        }
        else
        {
            q2.push(q1.front());
            q1.pop();
            sum2 += q2.back();
            sum1 -= q2.back();
            ans++;
        }
    }
    return -1;
}