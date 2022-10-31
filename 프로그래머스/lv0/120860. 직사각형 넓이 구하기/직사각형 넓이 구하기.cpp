#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int w = 0, h = 0;
    for (int i=1; i<dots.size(); i++)
    {
        if (dots[0][0] != dots[i][0]) w = abs(dots[0][0] - dots[i][0]);
        if (dots[0][1] != dots[i][1]) h = abs(dots[0][1] - dots[i][1]);
    }
    return w * h;
}