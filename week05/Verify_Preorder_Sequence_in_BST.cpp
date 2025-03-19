// TC: O(n) where n is the length of preorder sequence
// MC: O(n) recursive stack space

class Solution {
private:
    bool tryBuildBST(vector<int>& preorder, int& index, int low, int high) {
        if (index == preorder.size()) return true;

        int node = preorder[index];
        if (node <= low || node >= high) return false;

        index++;
        auto trySetLeft  = tryBuildBST(preorder, index, low,  node);
        auto trySetRight = tryBuildBST(preorder, index, node, high);

        return trySetLeft || trySetRight;
    }

public:
    bool verifyPreorder(vector<int>& preorder) {
        int globalIndex = 0;
        return tryBuildBST(preorder, globalIndex, INT_MIN, INT_MAX);
    }
};
