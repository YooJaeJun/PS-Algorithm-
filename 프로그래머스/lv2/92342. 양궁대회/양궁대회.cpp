#include <bits/stdc++.h>
using namespace std;

vector<int> player(11);
vector<int> ans;
int ansDiff = 0;

bool isWin(int& diff, const vector<int>& info)
{
    int enemy[11] = { 0, };
    int playerScore = 0, enemyScore = 0;
    for (int i = 0; i <= 10; i++)
    {
        if (player[i] == 0 and info[i] == 0) continue;
        else if (player[i] > info[i]) playerScore += 10 - i;
        else enemyScore += 10 - i;
    }
    diff = playerScore - enemyScore;
    return playerScore > enemyScore;
}

void comb(int curArrow, const int idx, const vector<int>& info)
{
    if (idx == 11)
    {
        int diff = 0;
        if (isWin(diff, info))
        {
            if (ans.empty() or diff > ansDiff)
            {
                ansDiff = diff;
                ans = player;
            }
            else if (diff == ansDiff)
            {
                for (int i = 10; i >= 0; i--)
                {
                    if (player[i] == ans[i]) continue;
                    else if (player[i] > ans[i])
                    {
                        ansDiff = diff;
                        ans = player;
                        return;
                    }
                    else return;
                }
            }
        }
        return;
    }

    for (int i = idx; i <= 10; i++)
    {
        if (curArrow < info[i] + 1 and i != 10) continue;   // 마지막엔 남은 거 다 넣기 위해 반복문 진행
        int arrow = info[i] + 1; // 하나보다 많은 개수만 넣기

        if (curArrow - arrow > 0) player[i] += arrow;
        else player[i] += curArrow; // 마지막

        comb(curArrow - arrow, i + 1, info);

        if (curArrow - arrow > 0) player[i] -= arrow;
        else player[i] -= curArrow;
    }
}

vector<int> solution(int n, vector<int> info) {
    comb(n, 0, info);
    vector<int> none{ -1 };
    return ans.empty() ? none : ans;
}