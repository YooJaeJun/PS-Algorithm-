#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> average;
    for (auto& elem : score)
    {
        average.push_back(elem[0] + elem[1]);
    }
    
    const int size = average.size();
    vector<int> ans(size);
    
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            if (i != j && average[i] >= average[j])
            {
                ans[i]++;
            }
        }
    }
    
    for (auto& elem : ans)
    {
        elem = size - elem;
    }
    
    return ans;
}