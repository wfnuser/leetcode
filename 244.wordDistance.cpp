// 个人觉得被注释掉的部分才是真正效率最高的解法 但没过

// class WordDistance {
// public:
//     unordered_map<string, int> pre;
//     unordered_map<string, unordered_map<string, int>> mem;
    
//     WordDistance(vector<string>& words) {
//         for (int i = 0; i < words.size(); i++) {
//             for (auto pair: pre) {
//                 string word1 = min(words[i], pair.first);
//                 string word2 = max(words[i], pair.first);
//                 if (!mem[word1][word2]) mem[word1][word2] = i - pair.second;
//                 else mem[word1][word2] = min(mem[word1][word2], i-pair.second);
//             }
//             pre[words[i]] = i;
//         }
//     }
    
//     int shortest(string word1, string word2) {
//         return word1 < word2 ? mem[word1][word2]: mem[word2][word1];
//     }
// };

class WordDistance {
public:
    unordered_map<string, vector<int>> indices;
    vector<string> words;
    
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            indices[words[i]].push_back(i);
        }
        this->words = words;
    }
    
    int shortest(string word1, string word2) {
        vector<int> indices1 = indices[word1];
        vector<int> indices2 = indices[word2];

        int i = 0;
        int j = 0;
        int ans = INT_MAX;

        while(i < indices1.size() && j < indices2.size()) {
            ans = min(ans, abs(indices2[j] - indices1[i]));
            if (indices1[i] < indices2[j]) {
                i++;
            } else {
                j++;
            }
        }

        return ans;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */