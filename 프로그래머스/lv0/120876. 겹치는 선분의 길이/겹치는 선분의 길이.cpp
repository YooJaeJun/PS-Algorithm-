#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<int>> lines) {
    map<int, int> dic;
    for (auto& elem : lines)
    {
        for (int i=elem[0]; i<elem[1]; i++)
        {
            dic[i]++;
        }
    }
    
    int answer = 0;
    for (auto& elem : dic)
    {
        if (elem.second >= 2) answer++;
    }
    return answer;
}