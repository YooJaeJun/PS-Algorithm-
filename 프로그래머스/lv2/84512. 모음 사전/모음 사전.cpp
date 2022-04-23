#include <string>
#include <vector>

using namespace std;

string alpha = "AEIOU";
int ans = -1;
bool isEnd = false;

void bt(string& word, string s) {
    ans++;
    if (word == s) {
        isEnd = true;
        return;
    }
    if (s.size() == 5) {
        return;
    }

    for (int i = 0; i != 5; i++) {
        bt(word, s + alpha[i]);
        if (isEnd) return;
    }
}

int solution(string word) {
    bt(word, "");
    return ans;
}

int main() {
    printf("%d", solution("AAAAE"));
    return 0;
}