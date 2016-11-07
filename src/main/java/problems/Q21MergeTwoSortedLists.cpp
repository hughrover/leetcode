#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(0);
        ListNode* curNode = dummyNode;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                curNode->next = l1;
                l1 = l1->next;
            } else {
                curNode->next = l2;
                l2 = l2->next;
            }
            curNode = curNode->next;
        }

        curNode->next = l1 == NULL ? l2 : l1;

        return dummyNode->next;
    }
};

void printList(ListNode* head) {
    while (head != NULL) {
        std::cout << head->val << " ";
        head = head->next;
    }
}

int main() {
    Solution* solution = new Solution();

    ListNode* node11 = new ListNode(1);
    ListNode* node12 = new ListNode(2);
    node11->next = node12;

    ListNode* node21 = new ListNode(2);
    ListNode* node22 = new ListNode(4);
    node21->next = node22;

    ListNode* newNode = solution->mergeTwoLists(node11, node21);
    printList(newNode);
}