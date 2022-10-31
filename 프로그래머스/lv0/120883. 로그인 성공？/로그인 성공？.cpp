#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    vector<string> result{"fail", "wrong pw", "login"};
    
    int temp = 0, ans = 0;
    for (auto& elem : db)
    {
        temp = 0;
        if (id_pw[0] == elem[0]) 
        {
            temp++;
            if(id_pw[1] == elem[1]) temp++;
        }
        
        if (temp == 2)
        {
            ans = 2;
            break;
        }
        else if (temp == 1)
        {
            ans = 1;
        }
    }
    
    return result[ans];
}