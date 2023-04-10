#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int size = sequence.size();
    int psum = 0, s = 0, e = 0;
    vector<int> answer{0, size - 1};
    
    for (int i=0; i<size; i++)
    {
        psum += sequence[e];
        
        while (psum > k && s <= e)
        {
            psum -= sequence[s];
            s++;
        }
        if (psum == k &&
           answer[1] - answer[0] > e - s)
        {
            answer[0] = s;
            answer[1] = e;
        }
        
        e++;
    }
    
    return answer;
}