#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string s = to_string(age);
    string answer;
    for (auto& ch : s)
    {
        answer += ch + '1';
    }
    return answer;
}