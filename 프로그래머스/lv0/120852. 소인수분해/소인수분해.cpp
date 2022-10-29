#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int divisor = 2;
    while(n > 1)
    {
        if (n % divisor == 0)
        {
            n /= divisor;
            answer.push_back(divisor);
            while(n % divisor == 0)
            {
                n /= divisor;
            }
        }
        divisor++;
    }
    
    return answer;
}