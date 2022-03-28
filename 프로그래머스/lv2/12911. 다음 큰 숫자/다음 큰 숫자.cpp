#include <string>
#include <vector>

using namespace std;

int solution(int n) {

    int sum = 0;
    int answer = 0;
    for (int i = n;; i++) {

        string s;
        int nIter = i;
        int sum2 = 0;
        do {
            int mod = nIter % 2;
            if (mod == 1) {
                if (i == n) { sum++; }
                else { sum2++; }
            }

            s = to_string(mod) + s;
            nIter /= 2;
        } while (nIter >= 2);
        s = '1' + s;

        if (sum == sum2) {
            answer = i;
            break;
        }
    }
    return answer;
}