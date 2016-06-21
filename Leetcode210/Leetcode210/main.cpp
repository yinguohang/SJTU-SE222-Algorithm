#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		if (numCourses == 1 && prerequisites.size() == 0) {
			vector<int> ans;
			ans.push_back(0);
			return ans;
		}
		list<int>* courses = new list<int>[numCourses];
		int* r = new int[numCourses];
		for (int i = 0; i < numCourses; i++) {
			r[i] = 0;
		}
		for (vector<pair<int, int>>::iterator i = prerequisites.begin(); i != prerequisites.end(); i++) {
			r[i->first]++;
			courses[i->second].push_back(i->first);
		}
		priority_queue<int> p;
		bool* s = new bool[numCourses];
		for (int i = 0; i < numCourses; i++) {
			s[i] = false;
			if (r[i] == 0) {
				p.push(i);
			}
		}
		vector<int> ans;
		while (!p.empty()) {
			int now = p.top();
			p.pop();
			s[now] = true;
			ans.push_back(now);
			for (list<int>::iterator iter = courses[now].begin(); iter != courses[now].end(); iter++) {
				if (--r[(*iter)] == 0)
					p.push(*iter);
			}
		}
		if (ans.size() != numCourses){
			vector<int> v;
			return v;
		}
		else {
			return ans;
		}
	}
};

int main() {
	vector<pair<int, int>> v;
	v.push_back(pair<int, int>(1, 0));
	v.push_back(pair<int, int>(2, 0));
	v.push_back(pair<int, int>(3, 1));
	v.push_back(pair<int, int>(3, 2));
	Solution sol;
	vector<int> ans = sol.findOrder(4, v);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}