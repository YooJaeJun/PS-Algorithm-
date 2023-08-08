#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(), [=](const vector<int>& v1, const vector<int>& v2)
    {
        return v1[1] < v2[1];
    });
    
    int cur = -1;
    int ans = 0;
    
    for (auto& elem : targets)
    {
        if (cur <= elem[0])
        {
            cur = elem[1];
            ans++;
        }
    }
    return ans;
}