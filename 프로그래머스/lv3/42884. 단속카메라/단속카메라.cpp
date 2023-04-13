#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), [&](vector<int> r1, vector<int> r2)
    {
         return r1[1] < r2[1];
    });
    
    int cam = -30001;
    int answer = 0;

    for (auto& route : routes)
    {
        if (cam < route[0])
        {
            cam = route[1];
            answer++;
        }
    }
    
    return answer;
}