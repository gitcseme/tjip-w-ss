// TC: O(N) where N is the number of nodes in the tree
// MC: O(N)

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return root;

        queue<TreeNode*> Q;
        Q.push(root);
        vector<int> levelSums;
        // BFS-1 for calculating level sums
        while (!Q.empty()) {
            int levelSum = 0;
            int levelSize = Q.size();
            for (int i = 0; i < levelSize; ++i) {
                auto node = Q.front();
                Q.pop();
                levelSum += node -> val;
                if (node -> left)  Q.push(node -> left);
                if (node -> right) Q.push(node -> right);
            }
            levelSums.push_back(levelSum);
        }

        Q.push(root);
        int level = 1;
        root -> val = 0;
        // BFS-2 for calculating cousins sum
        while(!Q.empty()) {
            int levelSize = Q.size();
            for (int i = 0; i < levelSize; ++i) {
                auto node = Q.front();
                Q.pop();

                int siblingSum = (node->left ? node->left->val : 0) + (node->right ? node->right->val : 0);
                if (node -> left) {
                    node -> left -> val = levelSums[level] - siblingSum;
                    Q.push(node -> left);
                }
                if (node -> right) {
                    node -> right -> val = levelSums[level] - siblingSum;
                    Q.push(node -> right);
                }
            }
            ++level;
        }

        return root;
    }
};
