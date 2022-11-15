#include <string>
#include <vector>
#include <deque>

using namespace std;

string solution(vector<int> food) {
    deque<int> dq;
    dq.push_back(0);
    
    for (int i=food.size()-1; i>=0; i--)
    {
        int temp = food[i] / 2;
        while (temp--)
        {
            dq.push_front(i);
            dq.push_back(i);
        }
    }
    
    string ans;
    for (int i=0; i<dq.size(); i++)
    {
        ans += dq[i] + '0';
    }
    return ans;
}