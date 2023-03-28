#include <string>
#include <vector>
#include <functional>
#include <cmath>

using namespace std;

int solution(int number, int limit, int power) {
    vector<int> memo(number + 1);
    
    function<int(int)> func = [&](const int n)
    {
        if (memo[n])
            return memo[n];
        
        int res = 0;
        
        for (int i=1; i*i<=n; i++)
        {
            if (n % i != 0)
                continue;
            if (i * i == n)
                res++;
            else
                res += 2;
        }
        return memo[n] = res > limit ? power : res;
    };
    
    int answer = 0;
    
    for (int i=number; i>=1; i--)
        answer += func(i);
    
    return answer;
}