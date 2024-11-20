// TC: O(N)
// MC: O(N)

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelLength = q.size();

            for (int i = 0; i < levelLength; ++i) {
                auto node = q.front();
                q.pop();

                if (node -> left)  q.push(node -> left);
                if (node -> right) q.push(node -> right);

                if (i < levelLength-1) {
                    node -> next = q.front();
                }
            }

        }

        return root;
    }
};
