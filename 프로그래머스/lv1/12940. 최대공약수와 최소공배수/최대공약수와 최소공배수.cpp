#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer(2);
    for (int i = 1; i <= n * m; i++) {
        if (!(n % i) && !(m % i)) {
            answer[0] = i;
        }
        if (!(i % n) && !(i % m)) {
            answer[1] = i;
            break;
        }
    }
    return answer;
}