#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer;
    for (auto& elem : strlist)
    {
        answer.push_back(elem.size());
    }
    return answer;
}