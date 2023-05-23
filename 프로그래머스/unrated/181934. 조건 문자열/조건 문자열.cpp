#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    int answer = 0;
    
    if (ineq == "<")
        answer = n < m;
    else
        answer = n > m;
    
    if (eq == "=")
        answer |= (n == m);
    else
        answer &= (n != m);
    
    return answer;
}