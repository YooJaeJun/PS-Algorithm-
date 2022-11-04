#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> elements) {
    int size = elements.size();
    vector<int> v(size * 2 - 1);
    for (int i=0; i<size; i++) v[i] = elements[i];
    for (int i=size; i<v.size(); i++) v[i] = elements[i - size];
    size = v.size();
    
    vector<int> pSum(size);
    pSum[0] = v[0];
    for (int i=1; i<size; i++)
    {
        pSum[i] = pSum[i - 1] + v[i];
    }
    
    unordered_map<int, int> dic;
    dic[pSum[0]]++;
    for (int i=1; i<size; i++)
    {
        int start = max(i - (int)elements.size(), 0);
        for (int j=start; j<i; j++)
        {
            dic[pSum[i] - pSum[j]]++;
        }
    }
    
    return dic.size();
}