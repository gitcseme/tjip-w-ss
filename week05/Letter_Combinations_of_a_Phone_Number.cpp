// TC: O(4^n) where max letters length is 4 and n is the number of digits.
// MC: O(4^n) recursive stack space + O(n) for combination collection. 

class Solution {
private:
    unordered_map<char, string> numLtrMap = {
        { '2', "abc" },
        { '3', "def" },
        { '4', "ghi" },
        { '5', "jkl" },
        { '6', "mno" },
        { '7', "pqrs" },
        { '8', "tuv" },
        { '9', "wxyz" }
    };

    void generate(const string& digits, string& combination, int pos, vector<string>& result) {
        if (pos == digits.size()) {
            if (!combination.empty()) 
                result.push_back(combination);
            return;
        }

        string letters = numLtrMap[digits[pos]];

        for (auto ch : letters) {
            combination.push_back(ch);
            generate(digits, combination, pos + 1, result);
            combination.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        string combination;
        vector<string> result;
        generate(digits, combination, 0, result);
        return result;
    }
};
