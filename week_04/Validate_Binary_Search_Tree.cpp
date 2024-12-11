class Solution {
private:
    bool checkValidity(TreeNode* root, long long L, long long R) {
        if (root == nullptr) return true;
        if (root -> val <= L || root -> val >= R) return false;

        bool leftBST  = checkValidity(root -> left,  L, root -> val);
        bool rightBST = checkValidity(root -> right, root -> val, R);

        return leftBST && rightBST;
    }

public:
    bool isValidBST(TreeNode* root) {
        long long negInf = INT_MIN * 1ll - 99;
        long long posInf = INT_MAX * 1ll + 99;
        return checkValidity(root, negInf, posInf);
    }
};
