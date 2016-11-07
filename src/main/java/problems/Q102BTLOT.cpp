#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<std::vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if (root == NULL) {
            return result;
        }

        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty()) {
            int size = Q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode *head = Q.front(); Q.pop();
                level.push_back(head->val);
                if (head->left != NULL) {
                    Q.push(head->left);
                }
                if (head->right != NULL) {
                    Q.push(head->right);
                }
            }

            result.push_back(level);
        }

        return result;
    }
};

void printVector(std::vector<std::vector<int> >  vec) {
    for(std::vector<std::vector<int> >::const_iterator iter = vec.begin(); iter != vec.end(); iter++) {
        for(std::vector<int>::const_iterator it = (*iter).begin(); it != (*iter).end(); it++) {
            std::cout << (*it) << " ";
        }
        std::cout << std::endl;
    }
}

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
    std::vector<std::vector<int> > vecVec = solution->levelOrder(root1);
    printVector(vecVec);

	return 0;
}