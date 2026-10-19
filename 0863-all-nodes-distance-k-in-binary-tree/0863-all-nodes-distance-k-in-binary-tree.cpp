
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void findParent(TreeNode* root, TreeNode* par) {
        if (root == NULL) return;

        parent[root] = par;

        findParent(root->left, root);
        findParent(root->right, root);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findParent(root, NULL);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int level = 0;

        while (!q.empty()) {
            if (level == k) break;

            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !visited.count(node->left)) {
                    q.push(node->left);
                    visited.insert(node->left);
                }

                if (node->right && !visited.count(node->right)) {
                    q.push(node->right);
                    visited.insert(node->right);
                }

                TreeNode* par = parent[node];

                if (par && !visited.count(par)) {
                    q.push(par);
                    visited.insert(par);
                }
            }

            level++;
        }

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
