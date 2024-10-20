class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valIdxMap;

        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            int need = target - nums[i];

            // check if map contains the needed element
            if (valIdxMap.count(need) > 0) { 
                return { valIdxMap[need], i };
            }

            valIdxMap[nums[i]] = i;
        }

        return {-1, -1};
    }
};
