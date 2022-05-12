#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) {
    stack<char> st;
    for(auto& ch : number)
    {
        while (st.empty() == false && st.top() < ch && k > 0)
        {
            st.pop();
            --k;
        }
        st.push(ch);
    }
    
    while(k > 0)
    {
        st.pop();
        --k;
    }
    
    string ans;
    while(st.empty() == false)
    {
        ans = st.top() + ans;
        st.pop();
    }
    return ans;
}