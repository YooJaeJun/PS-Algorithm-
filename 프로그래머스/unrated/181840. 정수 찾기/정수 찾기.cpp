#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> num_list, int n) {
    int answer = find(num_list.begin(), num_list.end(), n) - num_list.begin();
    return answer == num_list.size() ? 0 : 1;
}