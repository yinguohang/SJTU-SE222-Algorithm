#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	static bool compare(string a, string b) {
		return (a + b > b + a);
	}
	string largestNumber(vector<int>& nums) {
		vector<string> strings;
		int length = nums.size();
		if (length == 0)
			return "";
		for (int i = 0; i < length; i++) {
			strings.push_back(to_string(nums[i]));
		}
		sort(strings.begin(), strings.end(), compare);
		string ans;
		for (int i = 0; i < length; i++)
			ans += strings[i];
		int ptr = 0;
		length = ans.size();
		while (ptr < length-1 && ans[ptr] == '0')
			ptr++;
		ans = ans.substr(ptr);
		return ans;
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	Solution sol;
	cout << sol.largestNumber(a);
}