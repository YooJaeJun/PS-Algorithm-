#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> array) {
    unordered_map<int, int> dic;
    int maxn = 0;
    for (auto& elem : array) 
    {
        dic[elem]++;
        if (maxn < dic[elem]) maxn = dic[elem];
    }
    
    int overlap = 0, ans = 0;
    for (auto& elem : dic)
    {
        if (maxn == elem.second) 
        {
            ans = elem.first;
            overlap++;
        }
    }
    
    return overlap > 1 ? -1 : ans;
}