class Vector2D {
public:
    int i = 0;
    int j = 0;
    vector<vector<int>> vec;

    Vector2D(vector<vector<int>>& v) {
        vec = v;
        while(i < vec.size() && vec[i].size() == 0) {
            i++;
        }
    }
    
    int next() {
        int res = vec[i][j];
        
        if (j < vec[i].size() - 1) {
            j++;
        } else {
            i++;
            while (i < vec.size() && vec[i].size() == 0) {
                i++;
            }
            j = 0;
        }

        return res;
    }
    
    bool hasNext() {
        if (i >= vec.size()) return false;
        if (i == vec.size() - 1 && j >= vec[i].size()) return false;
        return true;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */