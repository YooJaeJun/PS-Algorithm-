#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    string s1 = to_string(a);
    s1 += to_string(b);
    string s2 = to_string(b);
    s2 += to_string(a);
    return s1 >= s2 ? stoi(s1) : stoi(s2);
}