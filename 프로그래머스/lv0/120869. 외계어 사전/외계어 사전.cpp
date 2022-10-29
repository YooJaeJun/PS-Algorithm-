#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 2;
    for (auto& str : dic)
    {
        bool flag = true;
        for (auto& alphabet : spell)
        {
            if (str.find(alphabet) == string::npos)
            {
                flag = false;
                break;
            }
        }
        if (flag) answer = 1;
    }
    return answer;
}