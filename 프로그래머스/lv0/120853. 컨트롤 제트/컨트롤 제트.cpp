#include <string>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

int solution(string s) {
    stringstream ss;
    ss.str(s);
    string temp;
    int answer = 0;
    stack<int> st;
    
    while(ss >> temp)
    {
        if (temp == "Z")
        {
            answer -= st.top();
            st.pop();
        }
        else
        {
            st.push(stoi(temp));
            answer += st.top();
        }
    }
    
    return answer;
}