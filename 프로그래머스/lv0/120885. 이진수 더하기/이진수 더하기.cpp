#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string bin1, string bin2) {
    string answer;
    if (bin1.size() < bin2.size())
    {
        swap(bin1, bin2);
    }
    int size = bin1.size();
    int factor = 0;
    
    for (int i=0; i<size; i++)
    {
        int idx1 = bin1.size() - 1 - i;
        int idx2 = bin2.size() - 1 - i;
        int res = bin1[idx1] - '0' + factor;
        if (idx2 >= 0) res += bin2[idx2] - '0';
        if (res > 1)
        {
            factor = 1;
            res -= 2;
        }
        else
        {
            factor = 0;
        }
        answer += to_string(res);
    }
    
    if (factor == 1) answer += '1';
    reverse(answer.begin(), answer.end());
    
    return answer;
}