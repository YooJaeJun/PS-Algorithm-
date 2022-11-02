#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<int>> dots) {
    unordered_map<int, int> dic;
    
    for (int i=0; i<dots.size()-1; i++)
    {
        for (int j=i+1; j<dots.size(); j++)
        {
            float temp = (float)(dots[j][1] - dots[i][1]) / (dots[j][0] - dots[i][0]);
            int incline = temp * 1000;
            if (dic[incline]) return 1;
            dic[incline] = 1;
        }
    }
    return 0;
}