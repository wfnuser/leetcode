class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string enc = "";
        for (auto str: strs) {
            enc += to_string(str.size()) + "$" + str;
        }
        return enc;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        int idx = 0;
        while(idx<s.size()) {
            string str;
            while(s[idx] != '$') {
                str += s[idx];
                idx++;
            }
            idx++;            
            int len = stoi(str);
            str = "";
            while(len) {
                str += s[idx];
                idx++;
                len--;
            }
            strs.push_back(str);
        }

        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));