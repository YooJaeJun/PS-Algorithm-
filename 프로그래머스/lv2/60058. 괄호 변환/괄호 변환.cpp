#include <bits/stdc++.h>
using namespace std;

bool isCorrect(string s)
{
    stack<char> st;
    for (auto& ch : s)
    {
        if (ch == ')' and
            st.empty() == false
            and st.top() == '(')
            st.pop();
        else st.push(ch);
    }
    return st.empty();
}

string recur(string& w)
{
    if (w == "") return "";
    string u, v;
    int cnt1 = 0, cnt2 = 0;
    bool uwflag = false;

    for (auto& ch : w)
    {
        if (uwflag) v += ch;
        else
        {
            u += ch;
            if (ch == '(') cnt1++;
            else cnt2++;

            if (cnt1 == cnt2)
            {
                uwflag = true;
            }
        }
    }
    if (isCorrect(u)) return u += recur(v);
    else
    {
        string s = '(' + recur(v) + ')';
        for (int i = 1; i < u.size() - 1; i++)
        {
            s += (u[i] == '(' ? ')' : '(');
        }
        return s;
    }
}

string solution(string p) {
    return recur(p);
}