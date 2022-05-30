#include <bits/stdc++.h>
using namespace std;
using vvi = vector<vector<int>>;
using vi = vector<int>;

vector<int> solution(int n) {
    vvi result(n);
    for(int i=0; i<n; i++)
    {
        result[i].resize(i + 1);
    }
    
    int num = 1;
    int limit = n;
    int x = 0, y = -1;
    while(1)
    {
        for(int i=0; i<limit; i++)
        {
            result[++y][x] = num++;
        }  
        if (--limit == 0) break;
        for(int i=0; i<limit; i++)
        {
            result[y][++x] = num++;
        }
        if (--limit == 0) break;
        for(int i=0; i<limit; i++)
        {
            result[--y][--x] = num++;
        }
        if (--limit == 0) break;
    }
    
    vi answer;
    int column = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=column; j++)
        {
            answer.push_back(result[i][j]);
        }   
        column++;
    }
    
    return answer;
}