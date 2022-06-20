#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> rel;
vector<vector<int>> history;  // 최소성 위해 성공한 것들 세이브
vector<int> cur;

bool checkUnique()
{
    vector<string> values;
    for (auto& r : rel)
    {
        string forSearch;
        for (int i = 0; i < (int)cur.size(); i++)
            forSearch += r[cur[i]];

        if (find(values.begin(), values.end(), forSearch) == values.end())
            values.push_back(forSearch);
        else 
            return false;
    }
    return true;
}

bool checkMinimal()
{
    if (cur.size() == 1) return true;

    for (int i = 0; i < (int)history.size(); i++)
    {
        bool flag = false;
        for (int j = 0; j < (int)history[i].size(); j++)
        {
            if (find(cur.begin(), cur.end(), history[i][j]) == cur.end())
            {
                flag = true;
                break;
            }
        }
        if (false == flag) return false;
    }
    return true;
}

void comb(int n, int idx)
{
    if (cur.size() == n)
    {
        if (checkUnique() and checkMinimal()) history.push_back(cur);
        return;
    }

    for (int i = idx; i < (int)rel[0].size(); i++)
    {
        cur.push_back(i);
        comb(n, i + 1);
        cur.pop_back();
    }
}

int solution(vector<vector<string>> relation) {
    rel = relation;

    for (int i = 1; i <= (int)rel[0].size(); i++)
        comb(i, 0);

    return history.size();
}