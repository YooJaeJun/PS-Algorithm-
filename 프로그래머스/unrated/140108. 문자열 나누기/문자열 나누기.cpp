#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int ans = 0, cur = 0;
    int n = s.size();

    while (cur < n)
    {
        char ch = s[cur++];
        int same = 1, diff = 0;

        while (1)
        {
            if (ch == s[cur++])
                same++;
            else
                diff++;

            if (same == diff || cur == n)
            {
                ans++;
                break;
            }
        }
    }

    return ans;
}