#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string myString) {
    for (auto& ch : myString)
        ch = toupper(ch);
    return myString;
}