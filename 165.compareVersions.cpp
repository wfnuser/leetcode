class Solution {
public:

    void setVersion(vector<int>& v, string version) {
        int tmp = 0;
        for(int i = 0; i < version.size(); i++) {
            if (version[i] == '.') {
                v.push_back(tmp);
                tmp = 0;
                continue;
            }
            tmp = tmp*10 + version[i] - '0';
        }
        v.push_back(tmp);
    }

    int compareVersion(string version1, string version2) {
        vector<int> v1;
        vector<int> v2;

        setVersion(v1, version1);
        setVersion(v2, version2);

        for (int i = 0; i < v1.size(); i++) {
            if (i < v2.size()) {
                if (v1[i] > v2[i]) return 1;
                if (v1[i] < v2[i]) return -1;
                continue;
            } else {
                if (v1[i] > 0) return 1;
            }
        }
        for (int i = v1.size(); i < v2.size(); i++) {
            if (v2[i] > 0) return -1;
        }

        return 0;
    }
};