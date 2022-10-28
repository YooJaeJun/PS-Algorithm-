#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int fac = 1;
    for (int i=1; i<=11; i++)
    {
        fac *= i;
        if (fac > n) return i - 1;
    }
}