#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    string temp;
    for (auto& ch : my_string)
    {
        if (ch >= '0' && ch <= '9')
        {
            temp += ch; 
        }
        else if (temp != "")
        {
            answer += stoi(temp);
            temp = "";
        }
    }
    if (temp != "") answer += stoi(temp);
    return answer;
}