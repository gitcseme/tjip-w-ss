// TC: O(N)
// MC: O(N)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        auto dummyHead = new Node(0);
        auto headPtr = dummyHead;
        auto current = head;
        unordered_map<Node*, Node*> nodeMap;

        // copy the original linked list
        while (current) {
            auto newNode = new Node(current -> val);
            nodeMap[current] = newNode;

            headPtr -> next = newNode;
            current = current -> next;
            headPtr = headPtr -> next;
        }

        current = head;
        headPtr = dummyHead -> next;
        // copy random pointers
        while (current) {
            headPtr -> random = nodeMap[current->random];
            current = current -> next;
            headPtr = headPtr -> next;
        }

        return dummyHead -> next;
    }
};
