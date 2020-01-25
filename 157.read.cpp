// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int res=0;
        for(int i=1;i<=n;i+=4){
            res+=read4(buf);
            buf+=4;
        }
        return n<res?n:res;  
    }
};