#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(string A, string B) {
    deque<char> dq;
    for (auto& ch : A) dq.push_back(ch);
    
    for (int i=0; i<A.size(); i++)
    {
        if (A == B) return i;
        
        dq.push_front(dq.back());
        dq.pop_back();
        
        for (int i=0; i<A.size(); i++) A[i] = dq[i];
    }
    return -1;
}