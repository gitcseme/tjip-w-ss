class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int L = 0, R = 0, res = 0;
        vector<int> f(256, 0);

        while (R < s.size()) {
            f[s[R]]++;
            while (f[s[R]] > 1) {
                f[s[L]]--;
                L++;
            }
            res = max(res, R - L + 1);
            R++;
        }

        return res;
    }
};
