#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<string, vector<int>> dicInfo;

void comb(vector<string>& vs, const int idx, const int score, const int depth, const int n)
{
    if (depth == n)
    {
        string s;
        for (auto& elem : vs) s += elem;
        dicInfo[s].push_back(score);
        return;
    }

    for (int i = idx; i < 4; i++)
    {
        string tmpSave = vs[i];
        vs[i] = "-";
        comb(vs, i + 1, score, depth + 1, n);
        vs[i] = tmpSave;
    }
}

vector<int> solution(vector<string> info, vector<string> query) {

    stringstream stream;
    for (auto& str : info)
    {
        vector<string> vs(4);
        stream.str(str);
        int score = 0;
        for (int i = 0; i < 4; i++) stream >> vs[i];
        stream >> score;
        for (int i = 0; i <= 4; i++) comb(vs, 0, score, 0, i);
        stream.clear();
    }

    for (auto& e : dicInfo)
    {
        sort(e.second.begin(), e.second.end());
    }

    vector<int> answer;
    for (auto& str : query)
    {
        string key;
        int score = 0;
        int ans = 0;

        stream.str(str);
        string tmpForPush;
        for (int i = 0; i < 7; i++)
        {
            stream >> tmpForPush;
            if (false == (i & 1)) // and 제외한 짝수 번째 칸
                key += tmpForPush;
        }
        stream >> score;

        ans = lower_bound(dicInfo[key].begin(), dicInfo[key].end(), score) - dicInfo[key].begin();
        ans = dicInfo[key].size() - ans;

        answer.push_back(ans);
        stream.clear();
    }

    return answer;
}