#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int answer = x;
    int sum = 0;
    while (true) {
        sum += (x % 10);
        x /= 10;
        if (x == 0) {
            break;
        }
    }
    return !(answer % sum);
}