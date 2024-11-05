// TC: O(N)
// MC: O(1)

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode();
        ListNode* current = dummyHead;
        int carry = 0;

        while (l1 || l2) {
            int x = l1 != nullptr ? l1 -> val : 0;
            int y = l2 != nullptr ? l2 -> val : 0;

            int sum = x + y + carry;
            current -> next = new ListNode(sum % 10);
            carry = sum / 10;
            current = current -> next;

            if (l1) l1 = l1 -> next;
            if (l2) l2 = l2 -> next;
        }

        if (carry > 0) 
            current -> next = new ListNode(carry);

        return dummyHead -> next;
    }
};
