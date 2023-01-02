#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int n = order.size();
    vector<int> v(n);
    
    for (int i=1; i<=n; i++) 
        v[i - 1] = i;
    
    int answer = 0;
    stack<int> st;
    int cur = 0;
    
    for (auto& elem : order)
    {
        if (!st.empty() && st.top() == elem)
        {
            st.pop();
            answer++;
        }
        else
        {
            while (cur < n && elem != v[cur])
            {
                st.push(v[cur]);
                cur++;
            }
            if (cur < n)
            {
                answer++;
                cur++;
            }
            else break;
        }
    }
    
    return answer;
}