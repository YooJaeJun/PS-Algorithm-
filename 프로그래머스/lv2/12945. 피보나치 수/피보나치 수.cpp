#include <string>
#include <vector>

using namespace std;

int f(int n) {
    int a = 0, b = 1, sum = 0;
    if (n <= 0) return a;
    if (n == 1) return b;
    for (int i = 2; i != n; i++) {
        sum = a + b;
        a = b;
        b = sum;
        a %= 1234567;
        b %= 1234567;
    }
    return a + b;
}

int solution(int n) {
    return f(n) % 1234567;
}