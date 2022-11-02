#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string polynomial) {
    stringstream ss;
    ss.str(polynomial);
    string temp;
    int sumX = 0, sumConst = 0;
    
    while(ss >> temp)
    {
        if (temp == "+") {}
        else if (temp.back() == 'x')
        {
            temp.pop_back();
            if (!temp.empty()) sumX += stoi(temp);
            else sumX++;
        }
        else
        {
            sumConst += stoi(temp);
        }
    }
    
    string answer;
    if (sumX != 0) 
    {
        if (sumX != 1) answer = to_string(sumX) + "x";
        else answer = "x";
        
        if (sumConst != 0) answer += " + " + to_string(sumConst);
    }
    else
    {
        if (sumConst != 0) answer += to_string(sumConst);
    }
    return answer;
}