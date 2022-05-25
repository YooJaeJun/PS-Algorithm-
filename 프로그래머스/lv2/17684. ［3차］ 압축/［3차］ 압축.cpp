#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string msg) {
    map<string, int> dic;

    for (int i = 1; i <= 26; i++)
    {
        const char alpha[2] = { static_cast<char>('A' + i - 1) };
        dic[alpha] = i;
    }

    int idx = 27;
    vector<int> ans;

    for (int i = 0; i < msg.size(); )
    {
        string str;
        str += msg[i];
        if (i < msg.size() - 1)
            str += msg[++i];

        if (dic[str] == 0)    // 사전에 없었으면
        {
            const char alpha[2] = { static_cast<char>(msg[i - 1]) };
            ans.push_back(dic[alpha]);
        }
        else
        {
            int forInsert = dic[str];
            while (dic[str] != 0)
            {
                forInsert = dic[str];
                str += msg[++i];
            }
            ans.push_back(forInsert);
        }

        dic[str] = idx++;
    }
    return ans;
}