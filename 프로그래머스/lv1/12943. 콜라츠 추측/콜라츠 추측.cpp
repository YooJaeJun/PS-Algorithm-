#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long n = (long long)num;
    for (int i = 0; i != 500; i++) {
        if (n == 1) {
            return i;
        }
        if (!(n % 2)) {
            n /= 2;
        }
        else {
            n = n * 3 + 1;
        }
    }
    return -1;
}