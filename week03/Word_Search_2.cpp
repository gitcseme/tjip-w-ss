class Solution {
private:
    class TrieNode {
    public:
        bool wordEnd;
        unordered_map<char, TrieNode*> next;
    };

    class Trie {
    public:
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }

        void insert(string &word) {
            auto curr = root;
            for (auto &ch : word) {
                if (curr -> next.count(ch) == 0) {
                    curr -> next[ch] = new TrieNode();
                }
                curr = curr -> next[ch];
            }
            curr -> wordEnd = true;
        }
    };

    Trie* initTrie(vector<string> &words) {
        auto trie = new Trie();
        for (auto word : words) {
            trie -> insert(word);
        }
        return trie;
    }

    vector<int> x_cord = { -1, 0, 1,  0 };
    vector<int> y_cord = {  0, 1, 0, -1 };
    int M, N;

    bool isValid(int i, int j) {
        return i >= 0 && i < M && j >= 0 && j < N;
    }


    void searchBoard(TrieNode* node, string &curr_word, vector<vector<char>>& board, 
        set<string> &result, vector<vector<bool>> &visited, int r, int c) 
    {
        if (node -> wordEnd) {
            result.insert(curr_word);
        }

        visited[r][c] = true;
        for (int i = 0; i < 4; ++i) {
            int x = r + x_cord[i];
            int y = c + y_cord[i]; 
            if (isValid(x, y) && !visited[x][y] && node -> next.count(board[x][y])) {
                curr_word.push_back(board[x][y]);
                searchBoard(node -> next[board[x][y]], curr_word, board, result, visited, x, y);
                curr_word.pop_back();
            }
        }
        visited[r][c] = false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        auto trie = initTrie(words);
        auto root = trie -> root;

        M = board.size(), N = board[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        set<string> result;

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                char ch = board[i][j];
                if (root -> next.count(ch)) {
                    string curr_word;
                    curr_word.push_back(ch);
                    searchBoard(root -> next[ch], curr_word, board, result, visited, i, j);
                }
            }
        }

        vector<string> ans;
        for (auto s : result) {
            ans.push_back(s);
        }
        return ans;
    }
};
