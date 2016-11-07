#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	if (head == NULL)
    		return head;

        ListNode *pre, *post;
        pre = post = head;

        int step = n;
        while (pre->next != NULL && --step >=0) {
        	pre = pre->next;
        	if (step == 0)
        		break;
        }

        if (step == 1)
        	return head->next;


        if (step == 0) {
        	while (pre->next != NULL) {
        		pre = pre->next;
        		post = post->next;
        	}

        	post->next = post->next->next;
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
	ListNode *n3 = new ListNode(3);
	// ListNode *n4 = new ListNode(4);

	n1->next = n2;
	n2->next = n3;
	// n3->next = n4;

	Solution* solution = new Solution();
	n1 = solution->removeNthFromEnd(n1, 1);

	printList(n1);
}