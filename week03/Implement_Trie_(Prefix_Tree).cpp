// TC: O(n) -> search, insert, starts-with
// MC: O(n) -> for trie nodes
class Trie {
private:
    class TrieNode {
    public:
        char ch;
        bool wordEnds = false;
        unordered_map<char, TrieNode*> next;
    };

public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        auto current = root;
        for(char &ch : word) {
            if (current -> next[ch] == nullptr) {
                current -> next[ch] = new TrieNode();
            }
            current = current -> next[ch];
        }
        current -> wordEnds = true;
    }
    
    bool search(string word, bool isPrefixSearch = false) {
        auto current = root;
        for (char &ch : word) {
            if (current -> next[ch] == nullptr) {
                return false;
            }
            current = current -> next[ch];
        }

        return isPrefixSearch || (current && current -> wordEnds);
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};
