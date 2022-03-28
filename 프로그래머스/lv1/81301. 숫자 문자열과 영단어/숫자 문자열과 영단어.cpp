#include <string>
#include <vector>

using namespace std;

string numstr_arr[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

class string_to_num {
public:
	explicit string_to_num(const string& s) : s_(s) {}
	void numstr_to_intstr() {
		//numstr은 "seven" 같이 문자열로 된 것을 의미함.
		//intstr은 "14" 같이 숫자처럼 보이는 문자열을 의미함.
		int order = 0;
		char numch = '0';
		string tmpstr = "";
		for (auto it = s_.begin(); it != s_.end(); it++) {
			if (*it <= '9') {
				intstr += *it;
			}
			else {
				tmpstr += *it;
				for (int i = 0; i != 10; i++) {
					//"one"을 "1"로 바꿔서 넣는.
					if (numstr_arr[i] == tmpstr) {
						tmpstr.clear();
						order = i;
						numch = '0' + order;	//아스키 코드 고려
						intstr += numch;
						break;
					}
				}
			}
		}
	}
	const int intstr_to_int() {	//문자열을 숫자로 ex.십의자리는 *10...
		int ret = 0;
		int multiple_num = 1;
		for (int i = intstr.size(); i != 0; i--) {
			ret += ((intstr[i - 1] - '0') * multiple_num);
			multiple_num *= 10;
		}
		return ret;
	}

private:
	string s_;
	string intstr;
};

int solution(string s) {
	int answer = 0;

	string_to_num st(s);
	st.numstr_to_intstr();
	answer = st.intstr_to_int();

	return answer;
}