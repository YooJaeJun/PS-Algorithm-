#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<vector<int>> v(rows + 1, vector<int>(columns + 1));
    for(int i=1;i<=rows;++i) 
        for(int j=1;j<=columns;++j) 
            v[i][j] = (i - 1) * columns + j;
    
    vector<int> answer;
    
    for(auto& query : queries)
    {
        int r = query[0];
        int c = query[1];
        int endr = query[2];
        int endc = query[3];
        int mn = 1e9;
        
        for(int i=c+1; i<=endc; ++i) {
            mn = min(mn, v[r][c]);
            swap(v[r][c], v[r][i]);
        }

        for(int i=r+1; i<=endr; ++i) {
            mn = min(mn, v[r][c]);
            swap(v[r][c], v[i][endc]);
        }
        
        for(int i=endc-1; i>=c; --i) {
            mn = min(mn, v[r][c]);
            swap(v[r][c], v[endr][i]);
        }
        
        for(int i=endr-1; i>=r; --i) {
            mn = min(mn, v[r][c]);
            swap(v[r][c], v[i][c]);
        }
        
        answer.push_back(mn);
    }
    
    return answer;
}