#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    for (auto& elem : array)
    {
        while(elem)
        {
            if (elem % 10 == 7) answer++;
            elem /= 10;
        }
    }
    return answer;
}