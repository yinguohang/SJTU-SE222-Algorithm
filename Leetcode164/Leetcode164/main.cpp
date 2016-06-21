#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		int n = nums.size();
		if (n < 2)
			return 0;
		int min = *min_element(nums.begin(), nums.end());
		int max = *max_element(nums.begin(), nums.end());
		if (min == max)
			return 0;
		double gap = double(max - min) / (n - 1);
		vector<int> pmin(n - 1, INT_MAX);
		vector<int> pmax(n - 1, INT_MIN);
		for (int i = 0; i < n; i++) {
			int index = int((nums[i] - min) / gap);
			if (index == n - 1)
				continue;
			if (pmin[index] > nums[i])
				pmin[index] = nums[i];
			if (pmax[index] < nums[i])
				pmax[index] = nums[i];
		}
		int ans = 0;
		int cmax = pmax[0];
		int temp;
		for (int i = 1; i < n - 1; i++) {
			if (pmin[i] != INT_MAX) {
				temp = pmin[i] - cmax;
				if (temp > ans)
					ans = temp;
				cmax = pmax[i];
			}
		}
		temp = max - cmax;
		if (temp > ans)
			ans = temp;
		return ans;
	}
};

/* 
// O(nlogn)
class Solution {
public:
	int maximumGap(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int max = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] - nums[i - 1] > max)
				max = nums[i] - nums[i - 1];
		}
		return max;
	}
};
*/

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> nums[i];
	}
	Solution sol;
	cout << sol.maximumGap(nums);
}