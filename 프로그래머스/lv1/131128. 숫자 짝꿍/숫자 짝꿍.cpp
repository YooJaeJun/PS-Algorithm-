#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    vector<int> vx(10), vy(10);
    
    for (auto& ch : X) vx[ch - '0']++;
    for (auto& ch : Y) vy[ch - '0']++;
    
    string answer;
    bool onlyZero = true;
    
    for (int i=0; i<10; i++)
    {
        if (vx[i] > 0 && vy[i] > 0)
        {
            int cnt = min(vx[i], vy[i]);
            while (cnt--)
            {
                answer += i + '0';
            }
            
            if (i != 0) onlyZero = false;
        }
    }
    
    if (answer.empty())
    {
        answer = "-1";
    }
    else if (onlyZero)
    {
        answer = "0";
    }
    else
    {
        sort(answer.begin(), answer.end(), greater<int>());
    }
    return answer;
}