// TC: O(N) where N is the size of the array
// SC: O(N) N number of TreeNode is created + O(log N) recursive stack space

class Solution {
private:
    TreeNode* buildBST(vector<int> &nums, int L, int R) {
        if (L > R) return nullptr;

        int mid = (L + R) / 2;
        auto node = new TreeNode(nums[mid]);
        node -> left =  buildBST(nums, L, mid - 1);
        node -> right = buildBST(nums, mid + 1, R);
        return node;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size()-1);
    }
};
