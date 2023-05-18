#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;
    int i = 0, j = 1;
    
    while (j < section.size())
    {
        if (section[j] - section[i] + 1 <= m)
            j++;
        else
        {
            i = j;
            j++;
            answer++;
        }
    }
    
    return answer;
}