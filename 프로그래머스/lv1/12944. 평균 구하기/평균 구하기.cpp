#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for (const int& elem : arr) {
        answer += elem;
    }
    return answer / arr.size();
}