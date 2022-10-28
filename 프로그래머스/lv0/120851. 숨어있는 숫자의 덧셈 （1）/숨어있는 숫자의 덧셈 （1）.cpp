#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    for (auto& ch : my_string)
    {
        if (ch >= '0' && ch <= '9') answer += ch - '0';
    }
    return answer;
}