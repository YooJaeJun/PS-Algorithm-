#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> dic;
    
    for (int i=0; i<survey.size(); i++)
    {
        if (choices[i] - 4 < 0)
        {
            dic[survey[i][0]] += abs(choices[i] - 4);
        }
        else
        {
            dic[survey[i][1]] += choices[i] - 4;
        }
    }
    
    answer += dic['R'] < dic['T'] ? 'T' : 'R';
    answer += dic['C'] < dic['F'] ? 'F' : 'C';
    answer += dic['J'] < dic['M'] ? 'M' : 'J';
    answer += dic['A'] < dic['N'] ? 'N' : 'A';
    
    return answer;
}