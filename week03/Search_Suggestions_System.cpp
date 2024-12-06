// N is the total products 
// L is the length of each product
// W is the length of search word

// TC: O(N * L) -> for building trie + O(W * L * 3) -> for dfs
// MC: O(N * L) -> for trie nodes


class Solution {
private:
    class TrieNode {
    public:
        bool end;
        unordered_map<char, TrieNode*> next;
    };

    class Trie {
    public:
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }

        void insert(string word) {
            auto curr = root;
            for (char &ch : word) {
                if (curr -> next[ch] == nullptr) {
                    curr -> next[ch] = new TrieNode();
                }
                curr = curr -> next[ch];
            }
            curr -> end = true;
        }
    };

    Trie* build(vector<string> &strs) {
        auto trie = new Trie();
        for (auto &str : strs) {
            trie -> insert(str);
        }
        return trie;
    }

    void dfs(TrieNode *node, string &inputStr, vector<string> &results) {
        if (node == nullptr || results.size() == 3) return;
        if (node -> end) {
            results.push_back(inputStr);
        }

        for (char ch = 'a'; ch <= 'z'; ++ch) {
            if (node -> next.count(ch)) {
                inputStr.push_back(ch);
                dfs(node -> next[ch], inputStr, results);
                inputStr.pop_back();
            }
        }
    }

public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> suggestions;
        auto trie = build(products);
        auto rootPtr = trie -> root;

        string typedWord = "";
        for (auto ch : searchWord) {
            typedWord.push_back(ch);
            rootPtr = (rootPtr) ? rootPtr -> next[ch] : nullptr;

            vector<string> results;
            dfs(rootPtr, typedWord, results);
            suggestions.push_back(results);        
        }

        return suggestions;
    }
};
