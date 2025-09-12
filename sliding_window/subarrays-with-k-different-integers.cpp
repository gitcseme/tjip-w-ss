/* TC: O(2n) ~ O(n)
 * SC: O(n)
*/

class Solution {
private:
    // counts the number of subarrays with at most k different numbers
    int atMostK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int L = 0, R = 0, res = 0;

        while (R < nums.size()) {
            freq[nums[R]]++;

            while (freq.size() > k) {
                freq[nums[L]]--;
                if (freq[nums[L]] == 0) {
                    freq.erase(nums[L]);
                }
                L++;
            }
            res += R - L + 1;
            R++;
        }

        return res;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1); // returns exactly k
    }
};
