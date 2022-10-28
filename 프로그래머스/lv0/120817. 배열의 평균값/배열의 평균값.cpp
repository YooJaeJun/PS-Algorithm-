#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    float sum = 0;
    for (auto& elem : numbers)
    {
        sum += elem;
    }
    return sum / (float)numbers.size();
}