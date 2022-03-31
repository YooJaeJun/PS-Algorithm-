#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<pair<int, int>> arr1;
    // 합
    int sum = brown + yellow;
    for (int h = 1; h <= sum; h++) { // 세로
        if (sum % h == 0) {
            int v = sum / h;    // 가로
            if (v < h) { break; }
            arr1.push_back({ v, h });
        }
    }
    // 노랑
    vector<pair<int, int>> arr2;
    for (int h = 1; h <= yellow; h++) { // 세로
        if (yellow % h == 0) {
            int v = yellow / h;    // 가로
            if (v < h) { break; }
            arr2.push_back({ v + 2, h + 2 });
        }
    }
    // 공통점
    vector<int> answer(2);
    for (auto& elem : arr1) {
        auto it = find(arr2.begin(), arr2.end(), elem);
        if (it != arr2.end()) {
            answer[0] = it->first;
            answer[1] = it->second;
        }
    }
    return answer;
}