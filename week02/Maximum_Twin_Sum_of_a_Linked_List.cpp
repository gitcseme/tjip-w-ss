// TC: O(N)
// MC: O(1)

class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextNode = nullptr;

        while (curr) {
            nextNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

public:
    int pairSum(ListNode* head) {
        auto slow = head;
        auto fast = head;

        // move slow to the head of second half
        while (fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        auto reversed = reverseList(slow);
        auto headPtr = head;
        int mxTwinSum = 0;

        while (reversed) {
            int sum = headPtr -> val + reversed -> val;
            mxTwinSum = max(mxTwinSum, sum);
            headPtr = headPtr -> next;
            reversed = reversed -> next;
        }

        return mxTwinSum;
    }
};
