class Twitter {
public:
    bool a[510][510];//a[i][j]=true 表示i关注了j
    deque<pair<int,int>> b[510];//每个b[i]保存i自己的最近10条推文时间和ID
    long long time = 0;//每个推文发表的时间
    Twitter() {
        memset(a, 0, sizeof a);//初始化
        for(int i = 0; i < 510; i++) a[i][i] = true;//自己必须关注自己
        for(int i = 0; i < 510; i++) b[i].clear();
        time = 0;
    }
    void postTweet(int x, int y) {//用户x发了一个推文y
        time++;
        if(b[x].size()>=10) b[x].pop_front();//把x最老的文章弹出
        b[x].push_back({time,y});
    }
    vector<int> getNewsFeed(int x) {//求出x所关注的人的最近10条消息
        priority_queue<pair<int,int>> q;//大根堆 发文越新 就越在前面 
        for(int i = 0; i < 510; i++){
            if(a[x][i]){//若x关注了i 则要把i的前10条推文纳入待选集
                for(auto v : b[i]) q.push(v);  
            }
        }
        vector<int> res;
        for(int i = 0; i < 10&&!q.empty(); i++) res.push_back(q.top().second),q.pop();//把最新的十条纳入答案
        return res;
    }
    void follow(int x, int y) {//x关注了y
        a[x][y] = true;
    }
    void unfollow(int x, int y) {//x取关y
        if(x!=y) a[x][y] = false;//注意 自己不能取关自己
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */