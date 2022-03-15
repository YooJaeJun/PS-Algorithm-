#include <vector>
long long sum(std::vector<int> &a) {
	long long ans = 0;
	for (const auto& elem : a) {
		ans += elem;
	}
	return ans;
}
