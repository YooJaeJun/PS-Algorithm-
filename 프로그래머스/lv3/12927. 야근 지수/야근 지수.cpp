#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    priority_queue<int> pq;
    for (auto& elem : works)
    {
        pq.push(elem);
    }
    
    for (int i=0; i<n; i++)
    {
        if (pq.top() > 0)
        {
            int temp = pq.top();
            pq.pop();
            pq.push(--temp);
        }
    }
    
    long long answer = 0;
    while(!pq.empty())
    {
        answer += pq.top() * pq.top();
        pq.pop();
    }
    return answer;
}