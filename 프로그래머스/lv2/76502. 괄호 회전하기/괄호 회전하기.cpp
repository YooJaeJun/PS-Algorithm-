#include <bits/stdc++.h>
using namespace std;

bool check(deque<char>& dq)
{
    stack<char> st;
    for(auto& ch : dq)
    {
        if (st.empty()) st.push(ch);
        else if (st.top() == '[' && ch == ']') st.pop();
        else if (st.top() == '{' && ch == '}') st.pop();
        else if (st.top() == '(' && ch == ')') st.pop();
        else st.push(ch);
    }
    return st.empty();
}

int solution(string s) {
    deque<char> dq;

    for(auto& ch : s) dq.push_back(ch);
    
    int answer = 0;
    for(int i=0; i<s.size(); i++)
    {
        if (check(dq)) answer++;
        dq.push_back(dq.front());
        dq.pop_front();
    }
    return answer;
}