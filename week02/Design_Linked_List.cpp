class MyLinkedList {
private:
    class Node {
    public:    
        int value;
        Node* next;
        Node(int _value, Node* _next) {
            value = _value;
            next = _next;
        }
    };

    int length;
    Node* dummyHead = nullptr;

public:
    MyLinkedList() {
        length = 0;
        dummyHead = new Node(0, nullptr);
    }

    // release memory
    ~MyLinkedList() {
        auto headPtr = dummyHead;
        while (length--) {
            auto nodeToRemove = headPtr;
            headPtr = headPtr -> next;
            delete(nodeToRemove);
        }
    }
    
    int get(int index) {
        if (index < 0 || index >= length) return -1;

        auto headPtr = dummyHead -> next;
        while (index--) {
            headPtr = headPtr -> next;
        }

        return headPtr -> value;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(length, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > length) return;
        
        auto headPtr = dummyHead;
        while (index--) {
            headPtr = headPtr -> next;
        }
        
        auto newNode = new Node(val, headPtr -> next);
        headPtr -> next = newNode;
        length++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= length) return;
        
        auto headPtr = dummyHead;
        while (index--) {
            headPtr = headPtr -> next;
        }

        auto nodeToDelete = headPtr -> next;
        headPtr -> next = headPtr -> next -> next;
        delete(nodeToDelete);
        length--;
    }
};
