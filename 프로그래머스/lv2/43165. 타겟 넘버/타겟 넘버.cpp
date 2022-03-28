#include <string>
#include <vector>
using namespace std;

static int plusminus[] = { 1, 0 };
static int result = 0;

void dfs(const int& depth, const vector<int>& numbers, const int& target, int& answer) {
    if (depth == numbers.size()) {
        if (result == target) {
            answer++;
        }
        return;
    }
    for (int i = 0; i < 2; i++) {   //i == 0 이면 num이 1, result에 +
        int num = plusminus[i];
        if (num == 1) {
            result += numbers[depth];
        }
        else {
            result -= numbers[depth];
        }
        dfs(depth + 1, numbers, target, answer);

        if (num == 1) {
            result -= numbers[depth];
        }
        else {
            result += numbers[depth];
        }
    }
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(0, numbers, target, answer);
    return answer;
}