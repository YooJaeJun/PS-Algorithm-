#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    return str2.find(str1) <= str2.size() - 1;
}