#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    stringstream ss;
    vector<int> nums;
    
    for (auto& elem : quiz)
    {
        ss.clear();
        nums.clear();
        string oper;
        
        ss.str(elem);
        string temp;
        while(ss >> temp)
        {
            if (temp == "+" || temp == "-") oper = temp;
            else if (temp == "=") {}
            else nums.push_back(stoi(temp));
        }
        
        if (oper == "+")
        {
            if (nums[0] + nums[1] == nums[2]) answer.push_back("O");
            else answer.push_back("X");
        }
        else
        {
            if (nums[0] - nums[1] == nums[2]) answer.push_back("O");
            else answer.push_back("X");
        }
    }
    
    return answer;
}