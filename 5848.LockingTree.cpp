class LockingTree {
public:
    struct TreeNode {
        int val;
        vector<TreeNode*> children;
        TreeNode *p;
        TreeNode(int x) : val(x), p(NULL) {
            children = vector<TreeNode*>();
        }
    };
    
    unordered_map<int, TreeNode*> m;
    
    LockingTree(vector<int>& parent) {
        TreeNode* n = new TreeNode(0);
        m[0] = n;
        for (int i = 1; i < parent.size(); i++) {
            TreeNode* n;
            if (m[i] != NULL) n = m[i];
            else {
                n = new TreeNode(0);
                m[i] = n;
            }
            if (m.find(parent[i]) == m.end()) m[parent[i]] = new TreeNode(0);
            
            n->p = m[parent[i]];
            n->p->children.push_back(n);
        }        
    }
    
    bool lock(int num, int user) {
        if (m[num]->val == 0) {
            m[num]->val = user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if (m[num]->val == user) {
            m[num]->val = 0;
            return true;
        }
        
        return false;
    }
    
    bool upgrade(int num, int user) {
        if (m[num]->val != 0) return false;
        TreeNode* p = m[num]->p;
        while (p != NULL) {
            if (p->val != 0) return false;
            p = p->p;
        }
        
        bool flag = false;
        for (auto n: m[num]->children) {
            if (dfs(n)) {
                flag = true;
                break;
            }
        }
        if (!flag) return false;
        
        unlockAll(m[num]);
        
        m[num]->val = user;
        
        return true;
    }
    
    bool dfs(TreeNode* node) {
        if (node == NULL) return false;
        if (node->val != 0) return true;
        for (auto n: node->children) {
            if (dfs(n)) {
                return true;
            }
        }
        return false;
    }
    
    void unlockAll(TreeNode* node) {
        if (node == NULL) return;
        if (node->val != 0) node->val = 0;
        for (auto n: node->children) {
            unlockAll(n);
        }
        return;
    }
};
