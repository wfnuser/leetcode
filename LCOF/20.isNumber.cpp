class Solution {
public:
    bool isNumber(string s) {
        int mp[9][6]={
            {-1,  0,  1,  2, -1,  3},
            {-1, -1, -1,  2, -1,  3},
            {-1, -1, -1, -1, -1,  4},
            {-1,  5, -1,  4,  6,  3},
            {-1,  5, -1, -1,  6,  4},
            {-1,  5, -1, -1, -1, -1},
            {-1, -1,  7, -1, -1,  8},
            {-1, -1, -1, -1, -1,  8},
            {-1,  5, -1, -1, -1,  8}
        };
        int now=0;
        for(int i=0;i<s.size();i++)
        {
            switch(s[i])
            {
                case '-': now=mp[now][2];break;
                case '+': now=mp[now][2];break;
                case ' ': now=mp[now][1];break;
                case '.': now=mp[now][3];break;
                case 'e': now=mp[now][4];break;
                case 'E': now=mp[now][4];break;
                default: 
                {
                    if(s[i]>='0' && s[i]<='9')
                        now=mp[now][5];
                    else
                        now=mp[now][0];
                }
            }
            if(now==-1) return false;
        }
        return now==3 || now==4 || now==5 || now==8 ;
    }
};