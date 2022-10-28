#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int answer = hp / 5;
    answer += hp % 5 / 3;
    answer += hp % 5 % 3;
    return answer;
}