#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int max(int x, int y) {
		if (x > y)
			return x;
		return y;
	}
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return 0;
		if (n == 0)
			return nums[1];
		int* c = new int[n];
		int* nc = new int[n];
		for (int i = 1; i < n; i++) {
			c[i] = 0;
			nc[i] = 0;
		}
		c[0] = nums[0];
		nc[0] = nums[0];
		for (int i = 1; i < n; i++) {
			c[i] = max(c[i - 1] + nums[i], nums[i]);
			nc[i] = max(nc[i - 1], c[i - 1]);
		}
		return max(c[n - 1], nc[n - 1]);
	}
};

int main() {
	vector<int> vec;
	int x;
	cin >> x;
	for (int i = 0; i < x; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	Solution sol;
	cout << sol.maxSubArray(vec);
}