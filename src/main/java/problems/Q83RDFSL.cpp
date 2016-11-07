#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	ListNode* tmp = head;
    	while (tmp != NULL && tmp->next != NULL) {
    		if (tmp->val == tmp->next->val) {
    			tmp->next = tmp->next->next;
    		} else {
    			tmp = tmp->next;
    		}
    	}
  		return head;
    }
};

void printList(ListNode* head) {
	while (head != NULL) {
		std::cout << head->val << " ";
		head = head->next;
	}
}

int main() {
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(2);
	ListNode *n4 = new ListNode(4);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	Solution* solution = new Solution();
	printList(solution->deleteDuplicates(n1));
	return 0;
}