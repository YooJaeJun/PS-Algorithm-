#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int minIdx = 0, mindiff = 1e9;
    for (int i=0; i<array.size(); i++)
    {
        int diff = abs(array[i] - n);
        if (mindiff >= diff)
        {
            if (mindiff == diff)
            {
                minIdx = array[minIdx] < array[i] ? minIdx : i;
            }
            else
            {
                minIdx = i;
            }
            mindiff = diff;
        }
    }
    return array[minIdx];
}