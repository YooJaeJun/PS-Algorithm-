#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int res = 0;
    for (auto& elem : array)
    {
        if (elem == n) res++;
    }
    return res;
}