#include <string>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
    long long answer = lcm(arr[0], arr[1]);
    for (int i = 2; i != arr.size(); i++) {
        answer = lcm(answer, arr[i]);
    }
    return answer;
}