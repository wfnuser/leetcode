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
        vector<string> numbers;
        queue<TreeNode*> Q;
        Q.push(root);

        while(!Q.empty()) {
            TreeNode* cur = Q.front();
            Q.pop();

            if (cur == NULL) {
                numbers.push_back("#");
            } else {
                numbers.push_back(to_string(cur->val));
                Q.push(cur->left);
                Q.push(cur->right);
            }
        }

        string ans = "";
        for (auto number: numbers) {
            ans += number;
            ans += ',';
        }
        ans.pop_back();
                
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "#") return NULL;
        
        TreeNode* root;
        vector<string> numbers;
        string tmp = "";
        for (auto c: data) {
            if (c == ',') {
                numbers.push_back(tmp);
                tmp = "";
            } else tmp += c;
        }
        numbers.push_back(tmp);

        if (numbers.size() == 0) return NULL;

        queue<TreeNode*> Q;
        root = new TreeNode(stoi(numbers[0]));
        Q.push(root);

        for (int i = 1; i < numbers.size(); i++) {
            TreeNode* cur = Q.front();
            if (cur) cout << cur->val << endl;
            else cout << "NULL" << endl;
            Q.pop();
            TreeNode* left;
            TreeNode* right;
            if (numbers[i] == "#") left = NULL;
            else left = new TreeNode(stoi(numbers[i]));

            i++;

            if (numbers[i] == "#") right = NULL;
            else right = new TreeNode(stoi(numbers[i]));

            cur->left = left;
            cur->right = right;

            if (cur->left != NULL) Q.push(cur->left);
            if (cur->right != NULL) Q.push(cur->right);
        }

        return root;
    }  
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));