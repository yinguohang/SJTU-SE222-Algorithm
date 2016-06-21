#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	int p1;
	int p2;
public:
	Solution() {
		p1 = 0; p2 = 0;
	}
	int next(vector<int>& nums1, vector<int>& nums2) {
		if (p1 == nums1.size()) {
			p2++;
			return nums2[p2 - 1];
		}
		if (p2 == nums2.size()) {
			p1++;
			return nums1[p1 - 1];
		}
		if (nums1[p1] >= nums2[p2]) {
			p2++;
			return nums2[p2 - 1];
		}
		else {
			p1++;
			return nums1[p1 - 1];
		}
	}
	double find(vector<int>& nums1, vector<int>& nums2, int x) {
		if (x == 1) {
			return next(nums1, nums2);
		}
		if (p1 == nums1.size()) {
			p2 += x;
			return nums2[p2 - 1];
		}
		if (p2 == nums2.size()) {
			p1 += x;
			return nums1[p1 - 1];
		}
		int mid1, mid2;
		int d1 = x / 2 - 1;
		int d2 = x / 2 - 1;
		if (p1 + d1 >= nums1.size()) {
			d1 = nums1.size() - 1 - p1;
			d2 = x / 2 * 2 - 1 - (nums1.size() - p1);
		}else if (p2 + d2 >= nums2.size()) {
			d2 = nums2.size() - 1 - p2;
			d1 = x / 2 * 2 - 1 - (nums2.size() - p2);
		}
		mid1 = nums1[p1 + d1];
		mid2 = nums2[p2 + d2];
		if (mid1 < mid2) {
			p1 += d1 + 1;
			return find(nums1, nums2, x - d1 - 1);
		}else if (mid1 > mid2) {
			p2 += d2 + 1;
			return find(nums1, nums2, x - d2 - 1);
		}else {
			if (x % 2 == 0) {
				p1 += d1 + 1;
				p2 += d2 + 1;
				return nums1[p1 - 1];
			} else {
				p1 += d1 + 1;
				p2 += d2 + 1;
				return next(nums1, nums2);
			}
		}
	}
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int l1 = nums1.size();
		int l2 = nums2.size();
		if (l1 + l2 == 0)
			return 0;
		if ((l1 + l2) % 2 == 0) {
			int t1 = find(nums1, nums2, (l1 + l2)/2);
			int t2 = next(nums1, nums2);
			return (t1 + t2) / 2.0;
		}else {
			return find(nums1, nums2, (l1 + l2 + 1) / 2);
		}
	}
};

int main() {
	int n1, n2;
	cin >> n1 >> n2;
	int x;
	vector<int> nums1;
	vector<int> nums2;
	for (int i = 0; i < n1; i++) {
		cin >> x;
		nums1.push_back(x);
	}
	for (int i = 0; i < n2; i++) {
		cin >> x;
		nums2.push_back(x);
	}
	Solution sol;
	cout<<sol.findMedianSortedArrays(nums1, nums2);
}