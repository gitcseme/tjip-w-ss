// TC: O(2^n) where n is the length of the input array
// MC: O(2^n) recursive stack space + O(2^n) for subset collection

class Solution {
private:
    vector<vector<int>> results;
    void generate(vector<int>& nums, int index, vector<int>& set) {
        if (index == nums.size()) {
            results.push_back(set);
            return;
        }

        set.push_back(nums[index]);
        generate(nums, index + 1, set);
        set.pop_back();
        generate(nums, index + 1, set);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> set;
        generate(nums, 0, set);
        return results;
    }
};
