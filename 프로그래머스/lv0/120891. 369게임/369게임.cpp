#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    while(order)
    {
        int n = order % 10;
        if (n == 3 || n == 6 || n == 9) answer++;
        order /= 10;
    }
    return answer;
}