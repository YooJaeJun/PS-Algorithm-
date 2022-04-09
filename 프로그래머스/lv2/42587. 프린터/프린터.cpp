#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    deque<pair<int, int>> dq;   // num(우선순위), priorities의 idx
    
    for (int i = 0; i != priorities.size(); i++) {
        dq.push_back({ priorities[i], i });
    }

    vector<int> ranks;
    int rank = 0;

    while(dq.empty() == false) {
        bool most = true;
        for (int j = 1; j != dq.size(); j++) {
            if (dq.front().first < dq[j].first) {
                dq.push_back(dq.front());
                dq.pop_front();
                most = false;
                break;
            }
        }
        if (most) {
            rank++;
            if (location == dq.front().second) {
                return rank;
            }
            dq.pop_front();
        }
    }
}