class Twitter {
    priority_queue<pair<int, int>> tweets; 
    unordered_map<int, int> tweetBy;
    unordered_map<int, unordered_set<int>> following;
    int tweetCnt = 0;

public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets.push(make_pair(tweetCnt++, tweetId));
        tweetBy[tweetId] = userId;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int, int>> copy = tweets;
        int maxLen = 10;
        while(!copy.empty() && maxLen){
            pair<int, int> tweet = copy.top();
            copy.pop();
            if (following[userId].find(tweetBy[tweet.second]) != following[userId].end() || tweetBy[tweet.second] == userId) {
                maxLen--;
                ans.push_back(tweet.second);
            }
        }
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followeeId == followerId) return;
        following[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followeeId == followerId) return;
        if (following[followerId].find(followeeId) != following[followerId].end()){
            following[followerId].erase(following[followerId].find(followeeId));
        }
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