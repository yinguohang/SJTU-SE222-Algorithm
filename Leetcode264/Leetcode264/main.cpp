#include <iostream>
using namespace std;

class Solution {
public:
	int min(int x, int y, int z) {
		if (x <= y && x <= z) {
			return x;
		}
		else {
			if (y <= z) {
				return y;
			}
			return z;
		}
	}
	int nthUglyNumber(int n) {
		if (n <= 0)
			return 0;
		int* ans = new int[n];
		ans[0] = 1;
		int i2 = 0;	// Index of 2
		int i3 = 0;	// Index of 3
		int i5 = 0; // Index of 5
		for (int i = 1; i < n; i++) {
			int n2 = ans[i2] * 2;
			int n3 = ans[i3] * 3;
			int n5 = ans[i5] * 5;
			int minn = min(n2, n3, n5);
			if (minn == n2) i2++;
			if (minn == n3) i3++;
			if (minn == n5) i5++;
			ans[i] = minn;
		}
		return ans[n - 1];
	}
};

int main() {
	int x;
	cin >> x;
	Solution sol;
	cout << sol.nthUglyNumber(x) << endl;
}

