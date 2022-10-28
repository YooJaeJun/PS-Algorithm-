#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    for (auto& elem : my_string)
    {
        if (elem >= 'A' && elem <= 'Z') elem -= 'A' - 'a';
    }
    sort(my_string.begin(), my_string.end());
    return my_string;
}