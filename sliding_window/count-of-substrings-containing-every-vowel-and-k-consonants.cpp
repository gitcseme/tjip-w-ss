/* TC: O(n) + O(n) = O(n)
 * SC: O(1)
*/

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int atLeastK(string& word, int k) {
        unordered_map<char, int> vowels;
        int L = 0, R = 0, consonents = 0, res = 0;

        while (R < word.size()) {
            if (isVowel(word[R])) {
                vowels[word[R]]++;
            }
            else {
                consonents++;
            }

            while (vowels.size() == 5 && consonents >= k) {
                res += word.size() - R;

                if (isVowel(word[L])) {
                    vowels[word[L]]--;
                    if (vowels[word[L]] == 0) {
                        vowels.erase(word[L]);
                    }
                }
                else {
                    consonents--;
                }
                L++;
            }
            R++;
        }
        return res;
    }

    int countOfSubstrings(string word, int k) {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }
};
