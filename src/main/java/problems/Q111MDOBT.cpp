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
    int minDepth(TreeNode* root) {
    	if (root == NULL)
    		return 0;
    	if (root->left == NULL && root->right == NULL)
    		return 1;
    	if (root->left != NULL && root->right != NULL) {
    		int leftMinDepth = minDepth(root->left);
    		int rightMinDepth = minDepth(root->right);
    		return 1 + (leftMinDepth <= rightMinDepth ? leftMinDepth : rightMinDepth);
    	}
        return root->left == NULL ? minDepth(root->right) + 1 : minDepth(root->left) + 1;
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
	cout << solution->minDepth(root1) << endl;
	return 0;
}