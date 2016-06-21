#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int min(int x, int y) {
		if (x < y) return x;
		return y;
	}
	int minDistance(string word1, string word2) {
		int l1 = word1.size();
		int l2 = word2.size();
		int** f = new int*[l1 + 1];
		for (int i = 0; i < l1 + 1; i++)
			f[i] = new int[l2 + 1];
		for (int i = 0; i < l1 + 1; i++)
			f[i][0] = i;
		for (int i = 0; i < l2 + 1; i++)
			f[0][i] = i;
		for (int i = 1; i < l1 + 1; i++)
			for (int j = 1; j < l2 + 1; j++) {
				f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
				if (word1[i - 1] == word2[j - 1])
					f[i][j] = min(f[i][j], f[i - 1][j - 1]);
				else
					f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
			}
		return f[l1][l2];
	}
};

int main() {
	string w1;
	string w2;
	cin >> w1;
	cin >> w2;
	Solution sol;
	cout << sol.minDistance(w1, w2);
}