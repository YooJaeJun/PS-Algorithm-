#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(string letter) {
    unordered_map<string, char> morse;
    morse[".-"] = 'a';
    morse["-..."] = 'b';
    morse["-.-."] = 'c';
    morse["-.."] = 'd';
    morse["."] = 'e';
    morse["..-."] = 'f';
    morse["--."] = 'g';
    morse["...."] = 'h';
    morse[".."] = 'i';
    morse[".---"] = 'j';
    morse["-.-"] = 'k';
    morse[".-.."] = 'l';
    morse["--"] = 'm';
    morse["-."] = 'n';
    morse["---"] = 'o';
    morse[".--."] = 'p';
    morse["--.-"] = 'q';
    morse[".-."] = 'r';
    morse["..."] = 's';
    morse["-"] = 't';
    morse["..-"] = 'u';
    morse["...-"] = 'v';
    morse[".--"] = 'w';
    morse["-..-"] = 'x';
    morse["-.--"] = 'y';
    morse["--.."] = 'z';
    
    string answer, temp;
    for (int i=0; i<letter.size(); i++)
    {
        if (letter[i] == ' ')
        {
            answer += morse[temp];
            temp = "";
        }
        else
        {
            temp += letter[i];
        }
    }
    answer += morse[temp];
    return answer;
}