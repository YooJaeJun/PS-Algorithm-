#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int minx = 1e9, miny = 1e9, maxx = 0, maxy = 0;
    
    int size = wallpaper.size();
    int xsize = wallpaper[0].size();
    for (int x=0; x!=size; x++)
    {
        for (int y=0; y!=xsize; y++)
        {
            if (wallpaper[x][y] == '#')
            {
                minx = min(minx, x);
                miny = min(miny, y);
                maxx = max(maxx, x);
                maxy = max(maxy, y);
            }
        }
    }
    
    vector<int> answer{minx, miny, maxx + 1, maxy + 1};
    return answer;
}