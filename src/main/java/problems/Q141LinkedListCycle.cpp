#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        bool flag = false;
        ListNode* p = head;
        ListNode* q = (head != NULL && head->next != NULL) ? head->next->next : NULL;

        while (p != NULL && q != NULL) {
            if (p == q) {
                flag = true;
                break;
            }
            else {
                p = p->next;
                q = q->next;
                if (q != NULL)
                    q = q->next;
            }
        }
        return flag;
    }
};

int main() {
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	n1->next = n2;
	n2->next = n1;

	Solution* solution = new Solution();
	cout << solution->hasCycle(n1);
	return 0;
}