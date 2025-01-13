// TC: O(K) where K is the k-th element asked for in question
// MC: O(K) recursion stack space

class Solution {
private:
    int kthElem;
    void dfs(TreeNode* root, int& k) {
        if (root == nullptr || k < 0) return;

        dfs(root -> left, k);

        --k;
        if (k == 0) kthElem = root -> val;

        dfs(root -> right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return kthElem;
    }
};
