class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0;
        int B = 0;
        unordered_map<char, int> sm;
        unordered_map<char, int> gm;
        
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) A++;
            sm[secret[i]]++;
            gm[guess[i]]++;
        }

        for (int i = 0; i < 10; i++) {
            cout << to_string(i) << " " << sm['0'+i] << " " << gm['0'+i] << endl;
            B += min(sm['0'+i], gm['0'+i]);
        }

        return to_string(A)+'A'+to_string(B-A)+'B';
    }
};