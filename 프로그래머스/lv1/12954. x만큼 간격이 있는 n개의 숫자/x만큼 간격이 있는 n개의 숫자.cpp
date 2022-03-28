#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    int x_fix = x;
    for (int i = 0; i != n; i++) {
        answer.push_back(x_fix);
        x_fix += x;
    }
    return answer;
}