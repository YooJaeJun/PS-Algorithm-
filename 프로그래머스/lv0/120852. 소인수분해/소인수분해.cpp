#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int temp = n;
    while(temp != 1)
    {
        for (int i=2; i<=temp; i++)
        {
            if (temp % i == 0)
            {
                answer.push_back(i);
                temp /= i;
                break;
            }
        }
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    
    return answer;
}