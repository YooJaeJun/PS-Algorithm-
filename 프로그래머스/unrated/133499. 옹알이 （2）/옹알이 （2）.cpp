#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for (auto& s : babbling)
    {
        bool sub = false;
        string prev;
        int size = s.size();
        
        for (int i=0; i<size; )
        {
            if (i + 1 >= size)
            {
                sub = false;
                break;
            }
            
            string temp = s.substr(i, 2);
            if (temp == prev)
            {
                sub = false;
                break;
            }
            else if (temp == "ye" || temp == "ma")
            {
                prev = temp;
                i += 2;
                sub = true;
            }
            else
            {
                if (i + 2 >= size)
                {
                    sub = false;
                    break;
                }
                
                temp += s[i + 2];
                if (temp == prev)
                {
                    sub = false;
                    break;
                }
                else if (temp == "aya" || temp == "woo")
                {
                    prev = temp;
                    i += 3;
                    sub = true;
                }
                else
                {
                    sub = false;
                    break;
                }
            }
        }
        
        if (sub)
            answer++;
    }
    
    return answer;
}