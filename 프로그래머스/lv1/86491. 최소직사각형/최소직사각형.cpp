#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    for (int i = 0; i != sizes.size(); i++) {
        sort(sizes[i].begin(), sizes[i].end());
    }
    int max_front = sizes[0].front();
    for (int i = 0; i != sizes.size(); i++) {
        max_front = max_front > sizes[i].front() ? max_front : sizes[i].front();
    }
    int max_back = sizes[0].back();
    for (int i = 0; i != sizes.size(); i++) {
        max_back = max_back > sizes[i].back() ? max_back : sizes[i].back();
    }
    answer = max_front * max_back;
    return answer;
}