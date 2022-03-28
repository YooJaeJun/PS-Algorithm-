#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum = i;
        for (int j = i + 1; j <= n; j++) {
            sum += j;
            if (sum > n) {
                break;
            }
            else if (sum == n) {
                answer++;
            }
        }
    }
    return answer + 1;  // 자신
}