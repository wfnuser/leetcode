class Node {
    public:
        bool isKey;
        Node *children[26];
};

class WordDictionary {
    Node* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
        root->isKey = false;
        for (int i = 0; i < 26; i++) {
            root->children[i] = NULL;
        }
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *p = root;
        for (auto c: word) {
            if (!p->children[c-'a']) { p->children[c-'a'] = new Node();}
            p = p->children[c-'a'];
        }
        p->isKey = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        queue<int> index;
        queue<Node*> qp;

        qp.push(root);
        index.push(0);

        while(!qp.empty()) {
            int i = index.front();
            index.pop();
            Node* node = qp.front();
            qp.pop();

            if (i == word.length() && node->isKey) return true;
            if (i == word.length()) continue;

            char c = word[i];

            if (c == '.') {
                for (int j = 0; j < 26; j++) {
                    if (node->children[j]) {
                        qp.push(node->children[j]);
                        index.push(i+1);
                    }
                }
            } else {
                if (!node->children[c-'a']) continue;
                qp.push(node->children[c-'a']);
                index.push(i+1);
            }

        }

        return false;

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */