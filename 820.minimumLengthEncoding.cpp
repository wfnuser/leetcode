struct TrieNode
{
    TrieNode *children[26]; 
};

class Solution {
public:
    int ans = 0;

    void dfs(TrieNode* node, int d) {
        bool flag = true;
        for(auto child: node->children) {
            if (child != NULL) {
                flag = false;
                dfs(child, d+1);
            }
        }
        if (flag) ans += (d+1);
    }

    int minimumLengthEncoding(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (auto word: words) {
            TrieNode* p = root;
            bool cnt = false;
            for (int i = word.size()-1; i>=0; i--) {
                if (p->children[word[i]-'a'] == NULL) {
                    p->children[word[i]-'a'] = new TrieNode();
                    p = p->children[word[i]-'a'];
                    cnt = true;
                } else {
                    p = p->children[word[i]-'a'];
                }
            }
        }

        TrieNode* p = root;
        dfs(p, 0);
        
        return ans;
    }
};