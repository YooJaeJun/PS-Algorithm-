#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> nodes;
vector<string> ans;
int totalDepth;
bool flag = true;

void dfs(string start) {
    flag = true;
    for (auto& elem : nodes)
    {
        if (elem.second.size() != 0)
        {
            flag = false;
            break;
        }
    }

    if (flag) return;

    for (auto& elem : nodes[start])
    {
        string nxt = elem;
        ans.push_back(nxt);
        nodes[start].erase(find(nodes[start].begin(), nodes[start].end(), nxt));

        dfs(nxt);

        if (flag) return;

        nodes[start].push_back(nxt);
        sort(nodes[start].begin(), nodes[start].end());

        ans.pop_back();
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    for (int i = 0; i != tickets.size(); i++)
        nodes[tickets[i][0]].push_back(tickets[i][1]);

    for (auto& elem : nodes)
        sort(elem.second.begin(), elem.second.end());

    totalDepth = tickets.size() * 2;
    ans.push_back("ICN");

    dfs("ICN");

    return ans;
}