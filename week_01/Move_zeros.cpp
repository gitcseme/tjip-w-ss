class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p = 0, len = nums.size();

        for (int i = 0; i < len; ++i) {
            if (nums[i] != 0) {
                nums[p] = nums[i];
                ++p;
            }
        }

        while (p < len) nums[p++] = 0;
    }
};
