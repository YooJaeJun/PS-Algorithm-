#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int answer = 0;
    for (const bool& elem : included)
    {
        if (elem)
            answer += a;
        a += d;
    }
    return answer;
}