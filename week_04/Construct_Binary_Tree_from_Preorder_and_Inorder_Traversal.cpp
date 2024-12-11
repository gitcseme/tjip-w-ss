// TC: O(N) where N is the size of inorder or preorder array
// MC: O(N) tree nodes + O(N) recursive stack space + O(N) for mapping

class Solution {
private:
    unordered_map<int, int> inMap;
    int preRootIdx = 0;
    
    TreeNode* construct(vector<int>& inorder, vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int rootValue = preorder[preRootIdx];
        auto root = new TreeNode(preorder[preRootIdx]);
        preRootIdx++;

        root -> left  = construct(inorder, preorder, inStart, inMap[rootValue] - 1);
        root -> right = construct(inorder, preorder, inMap[rootValue] + 1, inEnd);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inMap[inorder[i]] = i;
        }

        return construct(inorder, preorder, 0, inorder.size()-1);
    }
};
