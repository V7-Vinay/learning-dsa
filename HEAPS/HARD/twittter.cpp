class Twitter {

    int timeStamp;
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int,int>>> tweetMap;

public:

    Twitter() {
        timeStamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({timeStamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int,int>> pq;

        for(auto &tweet : tweetMap[userId])
            pq.push(tweet);

        for(auto &user : followMap[userId]){

            for(auto &tweet : tweetMap[user])
                pq.push(tweet);
        }

        vector<int> feed;

        while(!pq.empty() && feed.size() < 10){

            feed.push_back(pq.top().second);
            pq.pop();
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {

        if(followerId == followeeId)
            return;

        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        followMap[followerId].erase(followeeId);
    }
};