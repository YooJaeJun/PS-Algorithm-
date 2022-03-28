#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    if ((double)sqrt(n) - (long long)sqrt(n) == 0) {
        return pow(sqrt(n) + 1, 2);
    }
    else {
        return -1;
    }
}