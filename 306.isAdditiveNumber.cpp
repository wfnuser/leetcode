class Solution {
public:
    string add(string& a,string& b){
        int n1=a.size()-1;
        int n2=b.size()-1;
        int carry=0;
        string ans;
        while(n1>=0||n2>=0||carry>0){
            int t1=n1>=0?a[n1--]-'0':0;
            int t2=n2>=0?b[n2--]-'0':0;
            ans+=(t1+t2+carry)%10+'0';
            carry=(t1+t2+carry)>=10?1:0;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    bool dfs(int i, int j, int k, string& num) {
        if (num[i] == '0' && j-i != 1) return false;
        if (num[j] == '0' && k-j != 1) return false;
        string s1 = num.substr(i, j-i);
        string s2 = num.substr(j, k-j);
        string sum = add(s1, s2);

        if (sum.size() + k - 1 >= num.size()) return false;
        
        for (int p = k; p < k + sum.size(); p++) {
            if (num[p] != sum[p-k]) {
                return false;
            }
        }
        if (sum.size() + k - 1 == num.size()-1) return true;

        return dfs(j, k, k + sum.size(), num);
    }

    bool isAdditiveNumber(string num) {
        for (int i = 1; i <= num.size()/2; i++) {
            for (int j = i+1; j < num.size(); j++) {
                if(dfs(0, i, j, num)) return true;
            }
        }
        return false;
    }
};