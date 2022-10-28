#include <string>
#include <vector>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    for (auto& elem1 : s1)
    {
        for (auto& elem2 : s2)
        {
            if (elem1 == elem2) answer++;
        }
    }
    return answer;
}