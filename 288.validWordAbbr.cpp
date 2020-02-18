class ValidWordAbbr {
public:
    unordered_map<string, int> hash;
    unordered_map<string, int> wordCnt;

    ValidWordAbbr(vector<string>& dictionary) {
        for (auto word: dictionary) {
            if (!wordCnt[word]) {
                if (word.size() <= 2) {
                    hash[word]++;
                } else {
                    hash[word[0]+to_string(word.size()-2)+word[word.size()-1]]++;
                }
                wordCnt[word]++;
            }
        }
    }
    
    bool isUnique(string word) {
        if (word.size() <= 2) {
            if (hash.find(word) != hash.end()) {
                return hash[word] == 1;
            }
            return !hash[word];
        } else {
            if (wordCnt[word]) {
                return hash[word[0]+to_string(word.size()-2)+word[word.size()-1]] == 1;
            }
            return !hash[word[0]+to_string(word.size()-2)+word[word.size()-1]];
        }
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */