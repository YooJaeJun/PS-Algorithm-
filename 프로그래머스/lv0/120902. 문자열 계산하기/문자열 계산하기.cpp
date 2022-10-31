#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    vector<int> nums;
    string oper;
    string temp;
    for (auto& elem : my_string)
    {
        if (elem == ' ')
        {
            if (temp == "+" || temp == "-")
            {
                oper += temp;
            }
            else
            {
                nums.push_back(stoi(temp));
            }
            temp = "";
        }
        else
        {
            temp += elem;
        }
    }
    nums.push_back(stoi(temp));
    
    int ans = nums[0];
    for (int i=0; i<oper.size(); i++)
    {
        if (oper[i] == '+') ans += nums[i + 1];
        else ans -= nums[i + 1];
    }
    return ans;
}