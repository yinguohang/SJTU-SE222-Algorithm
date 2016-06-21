#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int max(int& a, int& b) {
		if (a > b)
			return a;
		return b;
	}
	int candy(vector<int>& ratings) {
		if (ratings.size() == 0)
			return 0;
		if (ratings.size() == 1)
			return 1;
		//First find all KENG
		int l = ratings.size();
		bool* k = new bool[l];
		for (int i = 1; i < l - 1; i++){
			if (ratings[i] <= ratings[i - 1] && ratings[i] <= ratings[i + 1]) {
				k[i] = true;
			} else {
				k[i] = false;
			}
		}
		if (ratings[1] >= ratings[0])
			k[0] = true;
		else
			k[0] = false;
		if (ratings[l - 1] <= ratings[l - 2])
			k[l - 1] = true;
		else
			k[l - 1] = false;
		int p = 0;
		int* candy = new int[l];
		for (int i = 0; i < l; i++) {
			candy[i] = 0;
		}
		while(1) {
			while ((p < l) && !k[p]) 
				p++;
			if (p == l)
				break;
			int t = p;
			int count = 1;
			candy[p] = 1;
			while ((t - 1) >= 0 && ratings[t - 1] > ratings[t]){
				count++;
				t--;
				candy[t] = max(candy[t], count);
			}
			count = 1;
			t = p;
			while ((t + 1) < l && ratings[t + 1] > ratings[t]) {
				count++;
				t++;
				candy[t] = max(candy[t], count);
			}
			p = t + 1;
		}
		int sum = 0;
		for (int i = 0; i < l; i++) {
			sum += candy[i];
		}
		return sum;
	}
};

int main() {
	int n;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	Solution sol;
	cout<<sol.candy(v);
}