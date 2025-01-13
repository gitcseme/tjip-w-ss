// TC: O(N) where N is the total number of nodes.
// MC: O(N) recursive stack space

class Solution {
private:
    int mxSum = INT_MIN;
    int findMaxPath(TreeNode* root) {
        if (root == nullptr) return 0;

        int mxLeft =  findMaxPath(root -> left);
        int mxRight = findMaxPath(root -> right);
        
        // calculate max path rooted at current node.
        int mxAtRoot = root -> val + mxLeft + mxRight;
        mxSum = max(mxSum, mxAtRoot);

        // propagate max chain upward
        int maxFromSubtrees = max(mxLeft, mxRight);
        int mxChainSum = max({root -> val, (root -> val + maxFromSubtrees), 0});
        return mxChainSum;
    }

public:
    int maxPathSumHelper(TreeNode* root) {
        mxSum = INT_MIN;
        findMaxPath(root);
        return mxSum;
    }
    int maxPathSum(TreeNode* root) {
        return maxPathSumHelper(root);
    }
};
