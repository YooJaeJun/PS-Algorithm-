#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    if (k & 1)
        for (auto& elem : arr)
            elem *= k;
    else
        for (auto& elem : arr)
            elem += k;
    
    return arr;
}