// TC: O(N) where N is the total number of nodes in the tree.
// MC: O(N) for queue

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return root;

        queue<Node*> Q;
        Q.push(root);

        while (!Q.empty()) {
            int levelLength = Q.size();
            
            for (int i = 0; i < levelLength; ++i) {
                auto u = Q.front();
                Q.pop();

                if (i+1 < levelLength) u -> next = Q.front();
                
                if (u -> left != nullptr)  Q.push(u -> left);
                if (u -> right != nullptr)  Q.push(u -> right);
            }
        }

        return root;
    }
};
