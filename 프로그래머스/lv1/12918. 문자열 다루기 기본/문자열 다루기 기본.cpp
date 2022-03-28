#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = false;
    if (s.size() == 4 || s.size() == 6) {
        for (const auto& elem : s) {
            if (elem >= '0' && elem <= '9') {
                answer = true;
            }
            else {
                return false;
            }
        }
    }
    return answer;
}