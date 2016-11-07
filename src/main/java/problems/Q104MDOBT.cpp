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
    int maxDepth(TreeNode* root) {
    	if (root == NULL)
    		return 0;
    	else if (root->left == NULL && root->right == NULL)
    		return 1;
    	else if (root->left == NULL || root->right == NULL)
    		return root->left == NULL ? 1 + maxDepth(root->right) : 1 + maxDepth(root->left);
    	else {
    		int len1 = maxDepth(root->left);
    		int len2 = maxDepth(root->right);
    		return len1 >= len2 ? 1 + len1 : 1 + len2;
    	}
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
	c12->left = c15;
	c12->right = c16;

	Solution* solution = new Solution();
	cout << solution->maxDepth(root1) << endl;
	return 0;
}