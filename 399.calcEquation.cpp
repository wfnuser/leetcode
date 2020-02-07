class Solution {
public:
    unordered_map<string, double> number;
    unordered_map<string, string> father;

    string find(string p) {
        if(p!=father[p]) {father[p] = find(father[p]);}
        return father[p];
    }

    void merge(string a, string b, double value) {
        string fa = find(a);
        string fb = find(b);

        double ratio = value * number[b] / number[a];

        for (auto e: number) {
            if (find(e.first) == fa) number[e.first] *= ratio; 
        }

        father[fb] = fa;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;

        for (int i = 0; i < equations.size(); i++) {
            vector<string> eq = equations[i];
            string a = eq[0];
            string b = eq[1];

            if (number.find(b) == number.end()) {
                number[b] = 1.0;
                father[b] = b;
            }
            if (number.find(a) == number.end()) {
                number[a] = values[i];
                father[a] = a;
            }
            merge(a, b, values[i]);            
        }

        for (auto q: queries) {
            if (number.find(q[0]) == number.end() || number.find(q[1]) == number.end() || find(q[0]) != find(q[1])) {
                ans.push_back(-1);
            } else {
                ans.push_back(number[q[0]] / number[q[1]]);
            }
        }

        return ans;
    }
};