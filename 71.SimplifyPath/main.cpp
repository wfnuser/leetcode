class Solution {
public:
    string simplifyPath(string path) {
        string tmp = "";
        vector<string> s; 
        vector<string>::iterator it;

        for(int i = 0; i < path.size(); i++) {
            if (path[i] == '/' || i == path.size() - 1) {
                if (i == path.size() - 1 && path[i] != '/'){
                    tmp = tmp + path[i];
                }
                if (tmp == "..") {
                    if (s.size()>0) {
                        s.erase(s.end());
                    }
                } else if (tmp == ".") {
                } else if (tmp == "") {
                } else {
                    s.push_back(tmp);
                }
                tmp = "";
            } else {
                tmp += path[i];
            }
        }
        for(it=s.begin();it!=s.end();it++) {
            tmp = tmp + "/"+(*it);
        }
        if (tmp == "") tmp = "/";

        return tmp;
    }
};
