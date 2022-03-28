#include <vector>
#include <cmath>
using namespace std;

bool is_prime(const int& num) {
    for (int j = 2; j * j <= num; j++) {   //소수는 2 ~ i제곱근까지의 루프로 판별
        if (num % j == 0) {
            return false;
        }
    }
    return true;
}

int solution(int n) {
    int answer = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            answer++;
        }
    }
    return answer;
}