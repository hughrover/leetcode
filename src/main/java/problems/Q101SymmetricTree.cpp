#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    	return isMirror(root, root);
    }

    bool isMirror(TreeNode* t1, TreeNode* t2) {
    	if (t1 == NULL && t2 == NULL) {
    		return true;
    	} else if (t1 == NULL || t2 == NULL) {
    		return false;
    	} else if (t1->val == t2->val) {
    		return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    	} else {
    		return false;
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
	std::cout << solution->isSymmetric(root1) << std::endl;

	return 0;
}