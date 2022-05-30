#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<string> solution(vector<vector<int>> line) {
    map<pair<ll, ll>, int> inter;
    ll minx = 1e10, maxx = -1e10;
    ll miny = 1e10, maxy = -1e10;
    // Ax + By + E = 0, Cx + Dy + F = 0
    // x = (BF - ED) / (AD - BC);
    // y = (AF - EC) / (AD - BC);
    for(int i=0; i<line.size(); i++)
    {
        for(int j=i+1; j<line.size(); j++)
        {
            ll A = line[i][0];
            ll B = line[i][1];
            ll E = line[i][2];
            ll C = line[j][0];
            ll D = line[j][1];
            ll F = line[j][2];
            ll denom = A * D - B * C;
            if (denom == 0) continue;
            
            double dx = (double)(B * F - E * D) / denom;
            double dy = (double)(A * F - E * C) / denom;
            ll x = dx;
            ll y = dy;
            
            if (x == dx && y == dy)
            {
                inter[{x, y}]++;
                minx = min(minx, x);
                maxx = max(maxx, x);
                miny = min(miny, y);
                maxy = max(maxy, y);
            }
        }
    }
    vector<string> answer(maxy - miny + 1);
    int idx = 0;
    for(ll y=miny; y<=maxy; y++)
    {
        for(ll x=minx; x<=maxx; x++)
        {
            if (inter[{x, y}]) answer[idx] += '*';
            else answer[idx] += '.';
        }
        idx++;
    }
    return answer;
}