#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	bool operator < (Interval&);
};

class Solution {
public:
	static bool compare(Interval a, Interval b) {
		if (a.start < b.start)
			return true;
		else if (a.start > b.start)
			return false;
		else
			return a.end < b.end;
	}
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> ans;
		if (intervals.size() == 0)
			return ans;
		sort(intervals.begin(), intervals.end(), compare);
		int start = intervals[0].start;
		int end = intervals[0].end;
		for (int i = 1; i < intervals.size(); i++) {
			int now_start = intervals[i].start;
			int now_end = intervals[i].end;
			if (now_end <= end)			//[[***[****]]***]
				continue;
			if (now_start <= end)		//[[****[***]]***]
				end = now_end;
			else {						//[[****]]***[***]
				ans.push_back(Interval(start, end));
				start = now_start;	
				end = now_end;
			}
		}
		ans.push_back(Interval(start, end));
		return ans;
	}
};

void print(vector<Interval> intervals) {
	for (int i = 0; i < intervals.size();i++) {
		cout << intervals[i].start << " " << intervals[i].end<<endl;
	}
}

int main() {
	int n;
	cin >> n;\
	vector<Interval> intervals;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		intervals.push_back(Interval(start, end));
	}
	Solution solution;
	print(solution.merge(intervals));
}