#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    for (int cur=i; cur<=j; cur++)
    {
        int temp = cur;
        while(temp)
        {
            if (temp % 10 == k) 
            {
                answer++;
            }
            temp /= 10;
        }
    }
    return answer;
}