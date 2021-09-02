class Twitter {
public:
    vector<pair<int,int>>recent;
    unordered_map<int,vector<int>>tweet;
    unordered_map<int,unordered_set<int>>follo;
    /** Initialize your data structure here. */
    Twitter() {
        recent.clear();
        tweet.clear();
        follo.clear();
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) 
    {
        tweet[userId].push_back(tweetId);
        recent.push_back({userId,tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) 
    {
        vector<int>ans;
        int n=recent.size();
        int cnt=0;
        
        for(int i=n-1;i>=0;i--)
        {
            if(recent[i].first==userId)
            {
                ans.push_back(recent[i].second);
                cnt++;
            }
            else if(follo[userId].find(recent[i].first)!=follo[userId].end())
            {
                ans.push_back(recent[i].second);
                cnt++;
            }
            if(cnt==10)
            {
                break;
            }
        }
        
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) 
    {
        follo[followerId].insert(followeeId);   
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) 
    {
        follo[followerId].erase(followeeId);
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
