#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    	ListNode* result;
    	ListNode* dummy = new ListNode(0);

    	if (head != NULL && head->next != NULL) {
    		result = head->next;
    		dummy->next = head;

    		while (dummy->next != NULL && dummy->next->next != NULL) {
    			ListNode* n1 = dummy->next;
    			ListNode* n2 = n1->next;
    			dummy->next = n2;

    			n1->next = n2->next;
    			n2->next = n1;
    			dummy = n1;
    		}

    	} else {
    		return head;
    	}

        return result;
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
	ListNode *n3 = new ListNode(3);
	// ListNode *n4 = new ListNode(4);

	n1->next = n2;
	n2->next = n3;
	// n3->next = n4;

	Solution* solution = new Solution();
	n1 = solution->swapPairs(n1);

	printList(n1);
	return 0;
}