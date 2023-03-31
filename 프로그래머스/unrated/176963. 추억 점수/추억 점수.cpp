#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> dic;
    
    for (int i=0; i<name.size(); i++)
        dic[name[i]] = yearning[i];
    
    for (auto& elem : photo)
    {
        int score = 0;
        for (auto& elem2 : elem)
        {
            score += dic[elem2];
        }
        answer.push_back(score);
    }
    
    return answer;
}