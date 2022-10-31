#include <string>
#include <vector>
#include <numeric>

using namespace std;

__int128 solution(int balls, int share) {
    long double answer = 1;
    
    int start = share + 1; 
    int divisor = balls - share;
    for (int i=start; i<=balls; i++)
    {
        answer *= i;
    }
    for (int divisor=balls - share; divisor>1; divisor--)
    {
        answer /= divisor;
    }
    
    return (__int128)answer;
}