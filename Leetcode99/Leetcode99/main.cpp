#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(0), right(0) {}
};

class Solution {
private:
	TreeNode* pre;
	TreeNode* wrong1;
	TreeNode* wrong2;
public:
	void LDR(TreeNode* root) {
		if (root->left != 0)
			LDR(root->left);
		if (pre != 0)
			if (pre->val > root->val) {
				if (!wrong1) {
					wrong1 = pre;
					wrong2 = root;
				}
				else {
					wrong2 = root;
				}
			}
		pre = root;
		if (root->right != 0)
			LDR(root->right);
	}
	void recoverTree(TreeNode* root) {
		if (root == 0)
			return;
		pre = 0;
		wrong1 = 0;
		wrong2 = 0;
		LDR(root);
		int temp = wrong1 -> val;
		wrong1->val = wrong2->val;
		wrong2->val = temp;
	}
};

void print(TreeNode* t) {
	if (!t)
		return;
	cout << t -> val <<" ";
	print(t->left);
	print(t->right);
}

int main(){
	TreeNode* t = new TreeNode(10);
	t->left = new TreeNode(9);
	t->left->left = new TreeNode(5);
	t->left->right = new TreeNode(8);
	t->left->right->right = new TreeNode(7);
	t->right = new TreeNode(12);
	Solution sol;
	print(t);
	sol.recoverTree(t);
	print(t);
}