#include <string>
#include <vector>
#include <functional>

using namespace std;

int solution(int balls, int share) {
    function<int(int, int)> combi = [&](int n, int r)
    {
        if (r == 0) return 1;
        else if (n == 1) return 1;
        else if (r >= n) return 1;
        return combi(n-1, r) + combi(n-1, r-1);
    };
    return combi(balls, share);
}