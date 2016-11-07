#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
    	int flag = 1;
    	dfs(root, &flag);
    	return flag == 1 ? true : false;
    }

    int dfs(TreeNode* root, int* flag) {
    	if (root == NULL) return 0;
    	int left, right;

    	if (root->left == NULL) left = 0;
    	else left = dfs(root->left, flag);

    	if (root->right == NULL) right = 0;
    	else right = dfs(root->right, flag);

    	int diff = left - right;
    	if (diff <= -2 || diff >= 2) *flag = 0;

    	return left >= right ? 1 + left : 1 + right;
    }
};

int main() {
	TreeNode* root1 = new TreeNode(1);
	TreeNode* c11 = new TreeNode(2);
	TreeNode* c12 = new TreeNode(2);
	TreeNode* c13 = new TreeNode(3);
	TreeNode* c14 = new TreeNode(4);
	TreeNode* c15 = new TreeNode(4);
	TreeNode* c16 = new TreeNode(4);

	root1->left = c11;
	root1->right = c12;

	c11->left = c13;
	c11->right = c14;

	c12->right = c16;

	c13->left = c15;

	Solution* solution = new Solution();
	cout << solution->isBalanced(root1) << endl;
	return 0;
}

/*
    深度优先遍历过程中，可以比较左右子树的高度差
*/
