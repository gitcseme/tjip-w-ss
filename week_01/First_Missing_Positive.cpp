class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size(), curr;

        // in-place indexing
        for (int i = 0; i < len; ++i) {
            curr = nums[i];

            while ((curr > 0 && curr <= len) && curr != i + 1 && nums[i] != nums[curr-1]) {
                swap(nums[i], nums[curr-1]);
                curr = nums[i];
            }
        }

        // check missing index 
        for (int i = 0; i < len; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return len + 1;
    }
};
