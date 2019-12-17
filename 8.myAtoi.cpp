class Solution {
public:
    bool isNum(char s) {
        if (s >= 48 && s <= 57) return true;
        return false;
    }

    int myAtoi(string str) {
        int size = str.size();
        int ans = 0;
        int flag=1;
        int pos=0;
        while(str[pos]==' '){pos++;};
        if (pos >= size) return ans;

        if(str[pos]=='-') {
            flag=-1; pos++;
        } else if(str[pos]=='+') {
            flag=1; pos++;
        }
        if (pos >= size) return ans;

        if(!isNum(str[pos])) return ans;

        while(pos<size&&isNum(str[pos])){
            int num = str[pos] - '0';
            if (flag>0) {
                if (INT_MAX/10<ans) return INT_MAX;
                if (INT_MAX/10==ans && (INT_MAX - ans*10) < num) return INT_MAX; 
            } else {
                if (INT_MAX/10<ans) return INT_MIN;
                if (INT_MAX/10==ans && (INT_MAX - ans*10)+1 < num) return INT_MIN; 
                if (INT_MAX/10==ans && (INT_MAX - ans*10)+1 == num) return INT_MIN; 
            }
            ans = ans*10 + num;
            pos++;
        }

        return flag*ans;
    }
};