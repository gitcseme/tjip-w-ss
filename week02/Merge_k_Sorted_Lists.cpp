// TC: O(N * log K)
// SC: O(K) auxiliary stack space

class Solution {
private:
    // O(N) -> to merge 2 linked list
    ListNode* mergeList(ListNode* h1, ListNode* h2) {
        ListNode* dummyHead = new ListNode();
        ListNode* headPtr = dummyHead;

        while (h1 && h2) {
            if (h1 -> val < h2 -> val) {
                headPtr -> next = h1;
                h1 = h1 -> next;
            }
            else {
                headPtr -> next = h2;
                h2 = h2 -> next;
            }
            headPtr = headPtr -> next;
        }

        if (h1) headPtr -> next = h1;
        if (h2) headPtr -> next = h2;

        return dummyHead -> next;
    }

    // O(N * log k) -> for k linked list to merge
    ListNode* merger(int L, int R, vector<ListNode*>& lists) {
        if (L > R)  return nullptr;
        if (L == R) return lists[L];
        
        int M = (L + R) / 2;
        auto left = merger(L, M, lists);
        auto right = merger(M + 1, R, lists);

        auto mergedList = mergeList(left, right);
        return mergedList;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merger(0, lists.size() - 1, lists);
    }
};
