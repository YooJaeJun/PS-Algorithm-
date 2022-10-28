#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    string s = to_string(n);
    for(auto& ch : s)
    {
        answer += ch - '0';
    }
    return answer;
}