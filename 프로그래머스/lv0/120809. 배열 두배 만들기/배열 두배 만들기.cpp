#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    for (auto& elem : numbers) elem *= 2;
    return numbers;
}