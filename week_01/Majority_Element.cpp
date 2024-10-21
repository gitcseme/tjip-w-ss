class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate, vote = 0, len = nums.size();

        for (int i = 0; i < len; ++i) {
            if (vote == 0) {
                candidate = nums[i];
                vote = 1;
                continue;
            }
            
            vote = nums[i] == candidate ? vote + 1 : vote - 1;
        }

        return candidate;
    }
};
