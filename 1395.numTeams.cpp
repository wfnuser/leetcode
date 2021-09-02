class Solution {
public:
    map<int,int> mp;
    int *c,size;
    int lowbit(int m){
        return m&(-m);
    }
    int get_sum(int m){
        int res=0;
        while(m){
            res+=c[m];
            m-=lowbit(m);
        }
        return res;
    }
    void insert(int m){
        //tree[m]=1;
        while(m<=size){
           c[m]+=1;
           m+=lowbit(m);
        }
    }
    int numTeams(vector<int>& rating) {
        int res=0;
        if(rating.size()<=2)return 0;
        vector<int> helper=rating;
        sort(rating.begin(),rating.end());
        size=rating.size();
        for(int i=0;i<size;i++){//离散化处理
            mp[rating[i]]=(i+1);
        }
        vector<int> lessl,lessr,largerl,largerr;
        c=new int[size+1];memset(c,0,sizeof(int)*(size+1));
        for(int i=0;i<size;i++){
            int now=mp[helper[i]];
            lessl.push_back(get_sum(now-1));
            largerl.push_back(get_sum(size)-get_sum(now));
            insert(now);
        }
        memset(c,0,sizeof(int)*(size+1));
        for(int i=size-1;i>=0;i--){
            int now=mp[helper[i]];
            lessr.push_back(get_sum(now-1));
            largerr.push_back(get_sum(size)-get_sum(now));
            insert(now);
        }
        for(int i=0;i<size;i++){
            res+=lessl[i]*largerr[size-i-1];
            res+=lessr[size-i-1]*largerl[i];
        }
        return res;
    }
};
