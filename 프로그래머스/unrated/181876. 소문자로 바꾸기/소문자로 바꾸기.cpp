#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    for (auto& ch : myString)
        ch = tolower(ch);
    return myString;
}