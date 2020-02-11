class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder == "#") return true;
        stack<string> S;
        string num = "";
        unordered_map<string, int> times;
        int cnt = 0;
        int visited = 0;
        for (char &c: preorder) {
            if (c == ',') cnt++;
        }

        int index = 1;
        
        for (char &c: preorder) {
            if (c == '#') {
                if (S.empty()) return false;
                times[S.top()]++;
                while(times[S.top()] == 2 && !S.empty()) {
                    S.pop();
                    if (S.empty()) break;
                    times[S.top()]++;
                }
                if (S.empty()) break;
                num = "#";
            }
            if (c == ',') {
                visited++;
                if (num == "#") {
                    num = "";
                    continue;
                }
                index++;
                num = to_string(index);
                S.push(num);
                num = "";
            }
            if (c <= '9' && c >= '0') {
                num += c;
            }
        }
        if (num != "") return false;

        for (auto time: times) {
            if (time.second != 2) return false;
        }


        if (visited < cnt) return false;

        return true;
    }
};