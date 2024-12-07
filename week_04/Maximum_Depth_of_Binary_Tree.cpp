// TC: O(N) where N is the number of nodes in the tree
// SC: O(N) recursive stack space

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftSubtreeHeight =  maxDepth(root -> left);
        int rightSubtreeHeight = maxDepth(root -> right);

        return 1 + max(leftSubtreeHeight, rightSubtreeHeight);
    }
};
