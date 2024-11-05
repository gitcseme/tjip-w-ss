// TC: O(N)
// MC: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor_combined = 0, len = nums.size();

        for (int i = 0; i < len; ++i) {
            xor_combined = xor_combined ^ nums[i];
        }

        return xor_combined;
    }
};
