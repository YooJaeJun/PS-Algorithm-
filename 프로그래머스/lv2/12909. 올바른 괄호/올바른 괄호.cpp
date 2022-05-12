#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    stack<char> st;
    for(auto& ch : s)
    {
        if(st.empty()) 
            st.push(ch);
        else
        {
            if(st.top() == '(' && ch == ')')
                st.pop();
            else if (st.top() == '(' && ch == '(')
                st.push(ch);
            else
                return false;
        }
    }
    return st.empty();
}