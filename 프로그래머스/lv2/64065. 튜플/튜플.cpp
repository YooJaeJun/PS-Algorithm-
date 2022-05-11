#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int>& v1, vector<int>& v2)
{
    return v1.size() < v2.size();
}

vector<int> solution(string s) {
    vector<vector<int>> vv;
    string tmp;
    for (int i = 1; i < s.size() - 1; ++i)
    {
        if (s[i] == '{')
            vv.resize(vv.size() + 1);
        else if (s[i] == '}' || (s[i] == ',' && tmp != "")) 
        {
            vv.back().push_back(stoi(tmp));
            tmp = "";            
        }
        else if (s[i] >= '0' && s[i] <= '9')
            tmp += s[i];
    }
    sort(vv.begin(), vv.end(), compare);

    vector<int> answer{ vv[0][0] };
    map<int, int> dic;
    dic[answer[0]] = 1;

    for (int i = 1; i < vv.size(); ++i)
    {
        for (int j = 0; j < vv[i].size(); ++j)
        {
            if (dic[vv[i][j]] != 1)
            {
                answer.push_back(vv[i][j]);
                dic[vv[i][j]] = 1;
            }
        }
    }

    return answer;
}