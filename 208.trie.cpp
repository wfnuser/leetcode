class Trie {
    struct trie_node
    {
        bool isKey;   // 标记该节点是否代表一个关键字
        trie_node *children[26]; // 各个子节点 
    };

    trie_node* root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new trie_node();
        root->isKey = false;
        for (int i = 0; i < 26; i++) {
            root->children[i] = NULL;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        trie_node* node = root;
        for (auto ch: word) {
            if (node->children[ch-'a'] == NULL) {
                node->children[ch-'a'] = new trie_node();
                node->children[ch-'a']->isKey = false;
            }
            node = node->children[ch-'a'];
        }
        node->isKey = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        trie_node* node = root;
        for (auto ch: word) {
            if (node->children[ch-'a'] == NULL) return false;
            node = node->children[ch-'a'];
        }
        return node->isKey;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        trie_node* node = root;
        for (auto ch: prefix) {
            if (node->children[ch-'a'] == NULL) return false;
            node = node->children[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */