// TC: O(N)
// MC: O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummyHead = new ListNode(0, head);
        auto slow = dummyHead;
        auto fast = dummyHead;
        
        while (n--) fast = fast -> next;

        while (fast -> next) {
            fast = fast -> next;
            slow = slow -> next;
        }

        auto noteToDelete = slow -> next;
        slow -> next = slow -> next -> next;
        delete(noteToDelete);

        return dummyHead -> next;
    }
};
