// TC: O(2^2N) where N is the number of pairs of parenthesis
// MC: O(N) + O(N) recursive stack space

class Solution {
public:
    void generate(string& pat, int open, int close, vector<string>& result) {
        if (open == 0 && close == 0) {
            result.push_back(pat);
            return;
        }

        if (open > 0) {
            pat.push_back('(');
            generate(pat, open - 1, close, result);
            pat.pop_back();
        }

        if (close > open) {
            pat.push_back(')');
            generate(pat, open, close - 1, result);
            pat.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string pat = "";
        generate(pat, n, n, result);
        return result;
    }
};
