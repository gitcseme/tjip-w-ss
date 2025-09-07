/* TC: O(2n) ~ O(n)
 * SC: O(n)
*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> freq;
        int L = 0, R = 0, res = 0;

        while (R < s.size()) {
            freq[s[R]]++;

            // rebalance if needed
            while (freq.size() > k) {
                freq[s[L]]--;
                if (freq[s[L]] == 0) {
                    freq.erase(s[L]);
                }
                L++;
            }

            res = max(res, R - L + 1);
            R++;
        }
        return res;
    }
};
