// TC: O(N) where N is the total number of nodes
// SC: O(N)

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "#";

        auto left = serialize(root -> left);
        auto right = serialize(root -> right);

        string st = to_string(root -> val) + "," + left + "," +  right;
        return st;
    }

    queue<string> tokenize(string input) {
        queue<string> q;
        stringstream ss(input);

        string token;
        while (getline(ss, token, ',')) {
            q.push(token);
        }

        return q;
    }

    TreeNode* buildTree(queue<string> &q) {
        if (q.empty()) return nullptr;

        auto token = q.front();
        q.pop();

        if (token == "#") return nullptr;

        auto node = new TreeNode(stoi(token));
        node -> left  = buildTree(q);
        node -> right = buildTree(q);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto tokenQ = tokenize(data);
        return buildTree(tokenQ);
    }
};
