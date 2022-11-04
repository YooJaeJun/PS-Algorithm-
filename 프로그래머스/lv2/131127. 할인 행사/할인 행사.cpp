#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    unordered_map<string, int> dic;
    for (int i=0; i<want.size(); i++)
    {
        dic[want[i]] = number[i];
    }
    
    int answer = 0;
    int end = discount.size() - 9;
    for (int i=0; i<end; i++)
    {
        unordered_map<string, int> tempDic;
        for (int j=i; j<i+10; j++)
        {
            tempDic[discount[j]]++;
        }
        
        bool flag = true;
        for (auto& elem : dic)
        {
            if (dic[elem.first] != tempDic[elem.first])
            {
                flag = false;
                break;
            }
        }
        if (flag) answer++;
    }
    
    return answer;
}