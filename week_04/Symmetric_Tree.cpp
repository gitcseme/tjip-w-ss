// TC: O(N) where N is the total number of notes in the tree
// SC: O(K) where K is depth of the tree

class Solution {
private:
    bool isMirror(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) return true;
        if (root1 == NULL || root2 == NULL) return false;
        if (root1 -> val != root2 -> val) return false;

        return isMirror(root1 -> left, root2 -> right) && isMirror(root1 -> right, root2 -> left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};
