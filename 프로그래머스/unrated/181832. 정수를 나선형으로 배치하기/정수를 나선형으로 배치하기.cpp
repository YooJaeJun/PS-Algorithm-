#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n));
    int r = 0, c = 0, cnt = 1;
    answer[0][0] = cnt++;
    
    while (1)
    {
        bool check = false;
        
        while (c + 1 < n && answer[r][c + 1] == 0)
        {
            answer[r][++c] = cnt++;
            check = true;
        }   
        
        while (r + 1 < n && answer[r + 1][c] == 0)
        {
            answer[++r][c] = cnt++;
            check = true;
        }
        
        while (c - 1 >= 0 && answer[r][c - 1] == 0)
        {
            answer[r][--c] = cnt++;
            check = true;
        }
        
        while (r - 1 >= 0 && answer[r - 1][c] == 0)
        {;
            answer[--r][c] = cnt++;
            check = true;
        }
        
        if (false == check)
            break;
    }
    
    return answer;
}