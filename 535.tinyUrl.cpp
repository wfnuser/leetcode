class Solution {
public:
    int count = 0;
    string word = "0123456789qwertyuioopasdfghjklzxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM";

    unordered_map<string, string> mmap;

    string randHash() {
        while(true){
            string key = "";
            for (int i = 0; i < 6; i++) {
                int id = rand() % 62;
                key += word[id];
            }
            if (mmap.count(key)) {
                continue;
            }
            return key;
        }
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key = randHash();
        mmap[key] = longUrl;
        return "http://" + key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string key = shortUrl.substr(7, shortUrl.length() - 7);
        return mmap[key];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));