#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i=4; i<=n; i++)
    {
        int measure = 0;
        for (int j=1; j<=i; j++)
        {
            if (i % j == 0) 
            {
                if (j * j == i) measure++;
                else measure += 2;
            }
            if (j >= i / j) break;
        }
        if (measure >= 3) answer++;
    }
    return answer;
}