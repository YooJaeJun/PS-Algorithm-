#include <vector>
#include <cmath>
using namespace std;

long long solution(int a, int b) {
    return (((long long)abs(b - a) + 1) * (a + b)) / 2;
}