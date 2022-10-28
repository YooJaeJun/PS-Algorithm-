#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer(2);
    answer[1] = max_element(array.begin(), array.end()) - array.begin();
    answer[0] = array[answer[1]];
    return answer;
}