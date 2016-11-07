#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
    	if (p != NULL && q != NULL && p->val == q->val) {
    		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    	}  else {
    		if (p == NULL && q == NULL) {
    			return true;
    		} else {
    			return false;
    		}
    	}
    }
};

int main() {
	TreeNode* root1 = new TreeNode(0);
	TreeNode* c11 = new TreeNode(1);
	TreeNode* c12 = new TreeNode(2);
	root1->left = c11;
	root1->right = c12;

	TreeNode* root2 = new TreeNode(0);
	TreeNode* c21 = new TreeNode(1);
	TreeNode* c22 = new TreeNode(2);
	root2->left = c21;
	root2->right = c22;

	Solution* solution = new Solution();
	std::cout << solution->isSameTree(root1, root2) << std::endl;

	return 0;
}