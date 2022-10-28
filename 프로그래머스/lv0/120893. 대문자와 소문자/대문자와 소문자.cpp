#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    for (auto& ch : my_string)
    {
        if (ch >= 'a' && ch <= 'z') ch = toupper(ch);
        else ch = tolower(ch);
    }
    return my_string;
}