/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if (!root) return ans;
        queue<TreeNode*> Q;
        Q.push(root);

        while(!Q.empty()) {
            TreeNode* node = Q.front();
            Q.pop();
            if (node == NULL) {
                ans += "#,";
                continue;
            }
            ans += to_string(node->val) + ",";
            Q.push(node->left);
            Q.push(node->right);
        }
        cout << ans << endl;

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        string nodeStr = "";
        queue<string> Q;
        while(!Q.empty()) {
            Q.pop();
        }
        for(int i = 0; i < data.size(); i++) {
            if (data[i] == ',') {
                Q.push(nodeStr);
                nodeStr = "";
                continue;
            }
            nodeStr += data[i];
        }
        
        TreeNode* root = new TreeNode(stoi(Q.front()));
        Q.pop();
        queue<TreeNode*> nodes;
        nodes.push(root);

        while(!Q.empty()) {
            TreeNode* node = nodes.front();
            nodes.pop();
            if (node == NULL) continue;
            string content = Q.front();
            Q.pop();
            if (content == "#") {
                node->left = NULL;
                nodes.push(node->left);
            } else {
                node->left = new TreeNode(stoi(content));
                nodes.push(node->left);
            }

            content = Q.front();
            Q.pop();
            if (content == "#") {
                node->right = NULL;
                nodes.push(node->right);
            } else {
                node->right = new TreeNode(stoi(content));
                nodes.push(node->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));