class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int> repeatCnt(n1 + 1, 0);
        vector<int> nextIdx(n1 + 1, 0);
        int j = 0, cnt = 0;
        //k表示段数，i表示s1的下标，j表示s2的下标
        for(int k = 1; k <= n1; k ++){
            for(int i = 0; i < s1.size(); i ++){
                if(s1[i] == s2[j]){
                    j ++;
                    if(j == s2.size()){
                        j = 0; cnt ++;
                    }
                }
            }
            repeatCnt[k] = cnt; //记录下前k段中s2的个数
            nextIdx[k] = j;
            for(int start = 0; start < k; start ++){
                //如果存在重复的nextIndex
                if(nextIdx[start] == j){
                    int interval = k - start;
                    int repeat = (n1 - start)/interval;
                    int patternCnt = (repeatCnt[k] - repeatCnt[start])*repeat;
                    int remainCnt = repeatCnt[start + (n1 - start) % interval];
                    return (patternCnt + remainCnt)/n2;
                }
            }
        }
        return repeatCnt[n1] / n2;
    }
};