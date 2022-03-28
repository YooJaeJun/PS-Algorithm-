#include <string>
#include <vector>

using namespace std;

//반복자를 사용하여 풀이
class id_check {
public:
	explicit id_check(const string& new_id) : new_id_(new_id) { }	//string 초기화 리스트
	void total_check() {
		the1st_upper_to_lower();
		the2nd_etc_string_delete();
		the3rd_double_dot_delete();
		the4th_firstlast_dot_delete();
		the5th_empty_to_a();
		the6th_size16_delete();
		the7th_min3_copypaste();
	}
	void the1st_upper_to_lower() {
		for (auto it = new_id_.begin(); it != new_id_.end(); it++) {
			if (*it >= 'A' && *it <= 'Z') {
				*it += ('a' - 'A');
			}
		}
	}
	void the2nd_etc_string_delete() {
		bool is_begin_handling = false;
		for (auto it = new_id_.begin(); it != new_id_.end();) {
			if ((*it < 'A' || *it > 'Z') && (*it < 'a' || *it > 'z') && (*it < '0' || *it > '9') && *it != '-' && *it != '_' && *it != '.') {
				it = new_id_.erase(it);
			}
			else {
				it++;
			}
		}
	}
	void the3rd_double_dot_delete() {
		for (auto it = new_id_.begin(); it != new_id_.end();) {
			if (*it == '.' && *(it + 1) == '.') {
				it = new_id_.erase(it);
			}
			else {
				it++;
			}
		}
	}
	void the4th_firstlast_dot_delete() {
		if (new_id_.size() != 0) {
			while (new_id_.front() == '.') {
				new_id_.erase(new_id_.begin());
			}
			while (new_id_[new_id_.size() - 1] == '.') {
				new_id_.pop_back();
			}
		}
	}
	void the5th_empty_to_a() {
		if (new_id_.size() == 0) {
			new_id_.push_back('a');
		}
	}
	void the6th_size16_delete() {
		while (new_id_.size() >= 16) {
			new_id_.pop_back();
			while (new_id_.back() == '.') {
				new_id_.pop_back();
			}
		}
	}
	void the7th_min3_copypaste() {
		if (new_id_.size() <= 2) {
			while (new_id_.size() != 3) {
				new_id_.push_back(new_id_.back());
			}
		}
	}
	const string& get_id() const {
		return new_id_;
	}
private:
	string new_id_;
};

string solution(string new_id) {
	string answer = "";

	id_check idc(new_id);
	idc.total_check();
	answer = idc.get_id();

	return answer;
}