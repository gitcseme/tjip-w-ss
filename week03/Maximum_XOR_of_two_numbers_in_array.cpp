class Solution {
private:
    class TrieNode {
    public:
        TrieNode* next[2];
        TrieNode() {
            next[0] = next[1] = nullptr;
        }
    };

    class Trie {
    public:
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }

        int checkBit(int num, int pos) {
            int state = num & (1 << pos);
            return state > 0 ? 1 : 0;
        }

        void onBit(int &num, int pos) {
            num = num | (1 << pos);
        }

        void insert(int num) {
            auto curr = root;
            for (int pos = 30; pos >= 0; --pos) {
                int currBit = checkBit(num, pos);
                if (curr -> next[currBit] == nullptr) {
                    curr -> next[currBit] = new TrieNode();
                }
                curr = curr -> next[currBit];
            }
        }

        int findBestMatch(int num) {
            auto curr = root;
            int bestMatch = 0;

            for (int pos = 30; pos >= 0; --pos) {
                int currBit = checkBit(num, pos);
                int oppositeBit = 1 - currBit;

                if (curr -> next[oppositeBit]) {
                    if (oppositeBit) onBit(bestMatch, pos);
                    curr = curr -> next[oppositeBit];
                }
                else {
                    if (currBit) onBit(bestMatch, pos);
                    curr = curr -> next[currBit];
                }
            }

            return bestMatch;
        }
    };

public:
    int findMaximumXOR(vector<int>& nums) {
        auto *trie = new Trie();
        trie -> insert(nums[0]);

        int mxXorSum = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int bestMatch = trie -> findBestMatch(nums[i]);
            mxXorSum = max(mxXorSum, bestMatch ^ nums[i]);

            trie -> insert(nums[i]);
        }

        return mxXorSum;
    }
};
