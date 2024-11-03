// TC: O(N)
// MC: O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;

        while (fast && fast -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};
