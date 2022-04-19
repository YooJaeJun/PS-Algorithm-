#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int max1 = citations.back();
    for (int i = max1; i >= 0; i--) {
        int idx = lower_bound(citations.begin(), citations.end(), i) - citations.begin();
        if (citations.size() - idx >= i) {
            return i;
        }
    }
    return 0;
}