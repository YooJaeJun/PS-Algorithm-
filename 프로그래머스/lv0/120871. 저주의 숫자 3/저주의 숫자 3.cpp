#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    for (int i=2; i<=n; i++)
    {
        answer++;
        
        bool loopBreak = false;
        while(!loopBreak)
        {
            string str = to_string(answer);
            for (auto& ch : str)
            {
                if (ch == '3') 
                {
                    answer++;
                    loopBreak = false;
                    break;
                }
                else loopBreak = true;
            }
            
            if (answer % 3 == 0) 
            {
                answer++;
                loopBreak = false;
            }
        }
    }
    return answer;
}