#include <string>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int t = 0;
    queue<int> q;
    for (auto& elem : truck_weights) {
        q.push(elem);
    }

    int idx = 0;
    int curWeight = weight;
    deque<pair<int, int>> inBridge; // 트럭종류(무게), 지난시간

    while (1) {
        for (auto& elem : inBridge) {
            if (++elem.second >= bridge_length) {
                curWeight += inBridge.front().first;
                inBridge.pop_front();
            }
        }

        if (q.empty() == false && curWeight >= q.front()) {
            curWeight -= q.front();
            inBridge.push_back({ q.front(), 0 });
            q.pop();
        }

        t++;

        if (q.empty() && inBridge.empty()) {
            break;
        }
    }
    return t;
}