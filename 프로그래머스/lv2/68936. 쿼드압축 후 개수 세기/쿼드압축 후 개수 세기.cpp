#include <bits/stdc++.h>
using namespace std;

int zeroCnt, oneCnt;

vector<int> devideConquer(vector<vector<int>>& arr, int x, int y, int siz)    // x가 행
{
    int zero = 0, one = 0;
    if (siz == 1)
    {
        zero = arr[x][y] == 0 ? zero + 1 : 0;
        one = arr[x][y] == 1 ? one + 1 : 0;
        return { zero, one };
    }

    int compare = arr[x][y];
    bool flag = true;
    for (int i = x; i < x + siz && flag; i++)
        for (int j = y; j < y + siz && flag; j++)
            if (compare != arr[i][j])
                flag = false;

    if (flag)
    {
        zero = arr[x][y] == 0 ? zero + 1 : 0;
        one = arr[x][y] == 1 ? one + 1 : 0;
        return { zero, one };
    }
    else
    {
        vector<int> ret1 = devideConquer(arr, x, y, siz / 2);
        vector<int> ret2 = devideConquer(arr, x, y + siz / 2, siz / 2);
        vector<int> ret3 = devideConquer(arr, x + siz / 2, y, siz / 2);
        vector<int> ret4 = devideConquer(arr, x + siz / 2, y + siz / 2, siz / 2);

        return { ret1[0] + ret2[0] + ret3[0] + ret4[0],
               ret1[1] + ret2[1] + ret3[1] + ret4[1] };
    }
}

vector<int> solution(vector<vector<int>> arr) {
    return devideConquer(arr, 0, 0, arr.size());
}