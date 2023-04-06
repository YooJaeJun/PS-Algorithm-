#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int size = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int winCount = 0;
    
    int i = 0, j = 0;
    while (i < size && j < size)
    {
        if (A[i] >= B[j])
            j = upper_bound(B.begin() + j + 1, B.end(), A[i]) - B.begin();
        
        if (j < size)
            winCount++;
        i++;
		j++;
    }
    
    return winCount;
}