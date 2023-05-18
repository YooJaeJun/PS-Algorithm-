#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    for (int i=0; i<my_string.size(); i++)
    {
        if (i == s)
        {
            for (int j=0; j<overwrite_string.size() && i<my_string.size(); j++)
            {
                my_string[i] = overwrite_string[j];
                i++;
            }
        }
    }
    
    return my_string;
}