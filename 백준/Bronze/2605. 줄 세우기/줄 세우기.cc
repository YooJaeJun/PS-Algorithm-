#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode* prev;
	ListNode() : val(0), prev(nullptr), next(nullptr) {}
};

void solution() {
	int n;
	cin >> n;
	vector<ListNode> nodes(n + 2);
	nodes[0].next = &nodes[1];	// 0 번째는 head

	for (int i = n; i > 0; i--) {	
		nodes[i].val = i;
		nodes[i].next = &nodes[i + 1];
		nodes[i].prev = &nodes[i - 1];
	}

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		while(num--) {
			// 단계 그려보기
			ListNode* prev = nodes[i].prev;
			ListNode* prev_prev = nodes[i].prev->prev;
			ListNode* prev_next = nodes[i].prev->next;

			nodes[i].prev->prev = &nodes[i];
			nodes[i].prev->next = nodes[i].next;

			nodes[i].next->prev = nodes[i].prev;

			nodes[i].next = prev;
			nodes[i].prev = prev_prev;
			prev_prev->next = &nodes[i];
		}
	}

	while(n--) {
		cout << nodes[0].next->val << ' ';
		nodes[0].next = nodes[0].next->next;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution();
	return 0;
}