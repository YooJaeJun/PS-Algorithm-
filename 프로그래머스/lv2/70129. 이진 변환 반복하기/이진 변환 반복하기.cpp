#include <bits/stdc++.h>
using namespace std;

int deleted = 0, cnt = 0;

string toBin(int n)
{
    string ret;
    while (1)
    {
        if (n == 1)
        {
            ret = '1' + ret;
            break;
        }
        ret = to_string(n % 2) + ret;
        n /= 2;
    }
    return ret;
}

string deleteZero(string s)
{
    string ret;
    for (auto& ch : s)
    {
        if (ch != '0') ret += ch;
        else ++deleted;
    }
    return ret;
}

vector<int> solution(string s) {
    string str = s;
    while (1)
    {
        ++cnt;
        str = deleteZero(str);
        int n = str.size();
        str = toBin(n);
        if (str == "1") break;
    }
    vector<int> answer{ cnt, deleted };
    return answer;
}