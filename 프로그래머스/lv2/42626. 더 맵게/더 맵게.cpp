#include <string>
#include <vector>
#include <queue>
using namespace std;

const int mix(const int& min1, const int& min2, int& answer) {
    answer++;
    return min1 + (min2 * 2);
}

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> q;

    for (const int& elem : scoville) {
        q.push(elem);
    }

    int min1, min2;
    while(true) {
        if (q.top() < K) {
            if (q.size() == 1) {
                answer = -1;
                break;
            }
            int min1 = q.top(); q.pop();
            int min2 = q.top(); q.pop();
            q.push(mix(min1, min2, answer));
        }
        else {
            break;
        }
    }
    return answer;
}