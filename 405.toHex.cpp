class Solution {
public:
    string toHex(int num) {
        if(num == 0) 
            return "0";
        string res = "";
        string hex[16] = {"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"};
        unsigned int numu = num;
        while(numu != 0)
        {
            res = hex[numu % 16] + res;  
            numu /= 16;
        }
        return res;
    }
};