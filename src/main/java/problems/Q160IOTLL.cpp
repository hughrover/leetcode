#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	ListNode *p1 = headA, *p2 = headB;

        while (p1 != NULL && p2 != NULL) {
        	if (p1 == p2) {
        		return p1;
        	} else {
        		if (p1->next != NULL && p2->next != NULL) {
        			p1 = p1->next;
        			p2 = p2->next;
        		} else if (p1->next == NULL && p2->next == NULL) {
        			return NULL;
        		} else if (p1->next == NULL) {
        			p1 = headB;
        			p2 = p2->next;
        		} else {
        			p2 = headA;
        			p1 = p1->next;
        		}
        	}
        }
        return NULL;
    }
};



int main() {
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);

	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(4);

	n1->next = n4;
	n2->next = n3;
	n3->next = n4;

	Solution* solution = new Solution();
	ListNode *p = solution->getIntersectionNode(n1, n2);
	cout << p->val;
}