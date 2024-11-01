class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int len = nums.size();
        vector<vector<int>> triplets;

        for (int i = 0; i < len; ++i) {
            int x = nums[i];
            int L = i + 1;
            int R = len - 1;
            // deal with duplicates
            while(i + 1 < len && nums[i] == nums[i + 1]) ++i;

            while (L < R) {
                if (nums[L] + nums[R] < -x) ++L;
                else if (nums[L] + nums[R] > -x) --R;
                else {
                    triplets.push_back({x, nums[L], nums[R]});
                    // deal with duplicates
                    while (L + 1 < R && nums[L] == nums[L + 1]) ++L;
                    while (R - 1 > L && nums[R] == nums[R-1]) --R;
                    ++L, --R;
                }
            }
        }
        return triplets;
    }
};
