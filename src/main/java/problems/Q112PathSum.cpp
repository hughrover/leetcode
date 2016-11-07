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
    bool hasPathSum(TreeNode* root, int sum) {
        int flag = 0;
        checkVal(root, sum, &flag);
        return flag == 1 ? true : false;
    }

    void checkVal(TreeNode* root, int sum, int* flag) {
    	if (root == NULL)
    		return;
    	if (root->left == NULL && root->right == NULL) {
    		if (root->val == sum) {
    			*flag = 1;
    		}
    	}
    	if (root->left != NULL) {
    		root->left->val += root->val;
    		checkVal(root->left, sum, flag);
    	}
    	if (root->right != NULL) {
    		root->right->val += root->val;
    		checkVal(root->right, sum, flag);
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
	cout << solution->hasPathSum(root1, 17) << endl;
	return 0;
}