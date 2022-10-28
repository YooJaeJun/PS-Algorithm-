#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    if (direction == "right")
    {
        int temp = numbers.back();
        numbers.pop_back();
        numbers.insert(numbers.begin(), temp);
    }
    else
    {
        int temp = numbers.front();
        numbers.erase(numbers.begin());
        numbers.push_back(temp);
    }
    return numbers;
}