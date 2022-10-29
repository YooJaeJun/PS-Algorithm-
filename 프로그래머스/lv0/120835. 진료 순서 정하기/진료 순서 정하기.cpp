#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> v;
    for (auto& elem : emergency) v.push_back(elem);
    sort(v.begin(), v.end(), greater<int>());
    
    unordered_map<int, int> dic;
    for (int i=0; i<v.size(); i++) dic[v[i]] = i + 1;
    
    vector<int> answer;
    for (auto& elem : emergency)
    {
        answer.push_back(dic[elem]);
    }
    return answer;
}