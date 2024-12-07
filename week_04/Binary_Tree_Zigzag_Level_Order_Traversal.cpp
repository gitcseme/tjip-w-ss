// N is the total number of nodes in the tree
// TC: O(N) = O(N) for each node to visit once. + O(N) to reverse total N nodes
// MC: O(N) = O(N) for the queue + O(N) for holding level nodes

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<TreeNode*> Q;
        Q.push(root);
        int order = 0;

        while(!Q.empty()) {
            int levelSize = Q.size();
            vector<int> levelNodes;

            for (int i = 0; i < levelSize; ++i) {
                auto node = Q.front();
                Q.pop();
                levelNodes.push_back(node -> val);

                if (node -> left)  Q.push(node -> left);
                if (node -> right) Q.push(node -> right);
            }
            if (order % 2 == 1) {
                reverse(levelNodes.begin(), levelNodes.end());
            }
            result.push_back(levelNodes);
            ++order;
        }

        return result;
    }
};
