#include <string>
#include <vector>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
	vector<string> ans;
	for (int i = 0; i < n; i++)
	{
		arr1[i] = arr1[i] | arr2[i];	// or
		string str;
		int total = n;
		while(total--)
		{
			if (arr1[i] & 1) str = "#" + str;	// &
			else str = " " + str;
			arr1[i] >>= 1;	// >>
		}
		ans.push_back(str);
	}
	return ans;
}