#include <bits/stdc++.h>
using namespace std;

void toDigit(string& s, int num, int digit)
{
    if (num == 0) return;
    toDigit(s, num / digit, digit);
    if (num % digit < 10)
        s += to_string(num % digit);
    else
        s += ('A' + (num % digit - 10));
}

string solution(int n, int t, int m, int p) {
    string ans;
    int order = 0;
    for (int i = 0; i <= t * m && ans.size() < t; i++)
    {
        string s;
        if (i == 0) s = "0";
        else toDigit(s, i, n);

        for (auto& ch : s)
        {
            if (++order % m == p || (m == p && order % m == 0))   // 튜브차례
            {
                ans += ch;
            }
            if (ans.size() == t) break;
        }
    }
    return ans;
}

int main()
{
    solution(16, 16, 2, 2);
    return 0;
}