#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int height) {
    int ans = 0;
    for (auto& elem : array)
    {
        if (height < elem) ans++;
    }
    return ans;
}