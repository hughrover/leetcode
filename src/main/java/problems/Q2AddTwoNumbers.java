package problems;

/**
 * User: chengcheng.liu
 * Date: 16/9/9
 */
public class Q2AddTwoNumbers {
    public static void main(String[] args) {
        ListNode l11 = new ListNode(1);
        ListNode l12 = new ListNode(2);
        ListNode l13 = new ListNode(9);
        ListNode l14 = new ListNode(9);
        l11.next = l12;
        l12.next = l13;
        l13.next = l14;

        ListNode l21 = new ListNode(9);
        l21.next = new ListNode(8);

        ListNode result = addTwoNumbers(l11, l21);

        while (result != null) {
            System.out.println(result.val);
            result = result.next;
        }
    }

    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode curNode = new ListNode(0);
        ListNode firstNode = curNode;
        ListNode prevNode = curNode;

        while (l1 != null && l2 != null) {
            int sum = l1.val + l2.val + carry;
            curNode.val = sum % 10;
            carry = sum / 10;

            l1 = l1.next;
            l2 = l2.next;

            ListNode nextNode = new ListNode(0);
            curNode.next = nextNode;
            prevNode = curNode;
            curNode = nextNode;
        }

        if (l1 != null || l2 != null ) {
            ListNode singleNode = l1 == null ? l2 : l1;
            while (singleNode != null) {
                int sum = singleNode.val + carry;
                curNode.val = sum % 10;
                carry = sum / 10;

                singleNode = singleNode.next;

                ListNode nextNode = new ListNode(0);
                curNode.next = nextNode;
                prevNode = curNode;
                curNode = nextNode;
            }
        }

        if (carry != 0) {
            curNode.val = 1;
        } else {
            prevNode.next = null;
        }

        return firstNode;
    }

    public static ListNode addTwoNumbers_Answer(ListNode l1, ListNode l2) {
        ListNode dummyHead = new ListNode(0);
        ListNode p = l1, q = l2, curr = dummyHead;
        int carry = 0;
        while (p != null || q != null) {
            int x = (p != null) ? p.val : 0;
            int y = (q != null) ? q.val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr.next = new ListNode(sum % 10);
            curr = curr.next;
            if (p != null) p = p.next;
            if (q != null) q = q.next;
        }
        if (carry > 0) {
            curr.next = new ListNode(carry);
        }
        return dummyHead.next;
    }

    static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }
}
