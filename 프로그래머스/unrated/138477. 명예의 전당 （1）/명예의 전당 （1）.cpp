#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (auto& elem : score)
    {
        pq.push(elem);
        if (pq.size() >= k + 1)
        {
            pq.pop();
        }
        answer.emplace_back(pq.top());
    }
    
    return answer;
}