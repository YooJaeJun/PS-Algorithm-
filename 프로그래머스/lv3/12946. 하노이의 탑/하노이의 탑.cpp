#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;

void move(int start, int end) {
    answer.push_back({start, end});
}

void hanoi(int n, int start, int end) {
    if(n == 1) {
        move(start, end);
        return;
    }
    int via = 6 - start - end;
    hanoi(n - 1, start, via);
    move(start, end);
    hanoi(n - 1, via, end);
}

vector<vector<int>> solution(int n) {
    hanoi(n, 1, 3);
    return answer;
}