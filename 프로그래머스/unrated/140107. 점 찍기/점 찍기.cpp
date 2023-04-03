#include <string>
#include <vector>

using namespace std;

long long DistSq(const long long a, const long long b)
{
    return a * a + b * b;
}

long long solution(int k, int d) {
    long long answer = 0;
    int mod = d % k;
    int save = d - mod;
    
    for (int i=0; i<=d; i += k)
    {
        for (int j=save; j>=0; j -= k)
        {
            if (DistSq(i, j) <= (long long)d * d)
            {
                answer += (j / k) + 1;
                save = j;
                break;
            }      
        }
    }
    
    return answer;
}