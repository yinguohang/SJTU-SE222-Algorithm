#include <iostream>
#include <vector>
//#include <map>
#include <queue>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//class Solution {	
//public:
//	ListNode* mergeKLists(vector<ListNode*>& lists) {
//		ListNode* ans = NULL;
//		ListNode* tail = NULL;
//		int n = lists.size();
//		multimap<int, ListNode*> m;
//		for (int i = 0; i < n; i++) {
//			if (lists[i] != NULL)
//				m.insert(make_pair(lists[i]->val, lists[i]));
//		}
//		while (m.begin() != m.end()) {
//			int listNumber = m.begin()->first;
//			ListNode* nodeNow = m.begin()->second;
//			ListNode* p = new ListNode(nodeNow->val);
//			if (!ans){
//				ans = p;
//				tail = p;
//			}else {
//				tail->next = p;
//				tail = p;
//			}
//			m.erase(m.begin());
//			if (nodeNow->next != NULL) {
//				m.insert(make_pair(nodeNow->next->val, nodeNow->next));
//			}
//		}
//		return ans;
//	}
//};

struct Compare {
	bool operator()(const ListNode*p, const ListNode* q)const {
		return p->val > q->val;
	}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode head(0);
		ListNode* tail = &head;
		priority_queue<ListNode*, vector<ListNode*>, Compare> q;
		for (int i = 0; i < lists.size(); i++) {
			if (lists[i] != NULL)
				q.push(lists[i]);
		}
		while (q.size() != 0) { 
			ListNode* nodeNow = q.top();
			q.pop();
			tail->next = nodeNow;
			tail = nodeNow;
			if (nodeNow->next != NULL) {
				q.push(nodeNow->next);
			}
		}
		tail->next = NULL;
		return head.next;
	}
};

int main() {
	int n, m;
	cin >> n;
	vector<ListNode*> lists;
	for (int i = 0; i < n; i++) {
		cin >> m;
		ListNode* head = NULL;
		ListNode* tail = NULL;
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			ListNode* q = new ListNode(x);
			if (!head) {
				head = q;
				tail = q;
			}
			else {
				tail->next = q;
				tail = q;
			}
		}
		lists.push_back(head);
	}
	Solution sol;
	ListNode* ans = sol.mergeKLists(lists);
	while (ans != 0) {
		cout << ans->val << " ";
		ans = ans->next;
	}
}