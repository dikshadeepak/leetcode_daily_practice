class Codec {
public:

    // 🔹 Serialize Tree
    void serializeHelper(TreeNode* root, string &s) {
        if (!root) {
            s += "#,";
            return;
        }

        s += to_string(root->val) + ",";
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s = "";
        serializeHelper(root, s);
        return s;
    }

    // 🔹 Deserialize Tree
    TreeNode* deserializeHelper(queue<string> &q) {
        if (q.empty()) return NULL;

        string val = q.front();
        q.pop();

        if (val == "#") return NULL;

        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(q);
        node->right = deserializeHelper(q);

        return node;
    }

    TreeNode* deserialize(string data) {
        queue<string> q;
        string temp = "";

        for (char c : data) {
            if (c == ',') {
                q.push(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        return deserializeHelper(q);
    }
};