#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    arr.erase(find(arr.begin(), arr.end(), *min_element(arr.begin(), arr.end())));
    if (arr.size() == 0) {
        arr.push_back(-1);
    }
    return arr;
}