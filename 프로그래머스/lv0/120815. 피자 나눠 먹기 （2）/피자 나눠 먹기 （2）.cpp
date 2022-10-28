#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    for (int i=1; i<=n; i++)
    {
        if ((6 * i) % n == 0)
        {
            return i;
        }
    }
}