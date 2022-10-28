#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer;
    for (auto& ch : my_string)
    {
        switch(ch)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                break;
            default:
                answer += ch;
        }
    }
    return answer;
}