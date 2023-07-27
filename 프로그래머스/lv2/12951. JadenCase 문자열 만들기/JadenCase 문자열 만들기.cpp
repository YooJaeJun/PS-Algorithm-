#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    bool first = true;
    
    for (auto& ch : s)
    {
        if (ch == ' ')
            first = true;
        else
        {
            if (first && ch >= 'a' && ch <= 'z')
                ch = toupper(ch);
            else if (false == first)
                ch = tolower(ch);
        
            first = false;
        }
    }
    
    return s;
}