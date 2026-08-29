class Twitter {
public:
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        auto& list = tweets[userId];
        list.push_back({timeStamp,tweetId});
        ++timeStamp;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;

        auto& set = userTofollowees[userId];

        for(int p : set){
            for(const auto& [stamp, tweet] : tweets[p])
                pq.push({stamp, tweet});
        }
        
        for(const auto& [stamp, tweet] : tweets[userId])
            pq.push({stamp, tweet});

        vector<int> feed;
        feed.reserve(10);

        while(!pq.empty() && feed.size() < 10){
            feed.push_back(pq.top().second);
            pq.pop();
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        userTofollowees[followerId].insert(followeeId);
        userTofollowers[followeeId].insert(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userTofollowees[followerId].erase(followeeId);
        userTofollowers[followeeId].erase(followerId);
    }
private:
    // user -> list of people hes following
    unordered_map<int, unordered_set<int>> userTofollowees;
    // user -> list of people who follow him
    unordered_map<int, unordered_set<int>> userTofollowers;
    // user -> list of tweets (stamp, tweet) 
    unordered_map<int, vector<pair<int,int>>> tweets;
    int timeStamp;
};