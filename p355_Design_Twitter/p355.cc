#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Twitter {
    unordered_map<int, deque<int> > feeds;
    unordered_map<int, unordered_set<int> > followers;
    unordered_map<int, unordered_set<int> > following;
    unordered_map<int, int> tweetOwner;
    unordered_map<int, int> tweetTime;
    unordered_map<int, deque<int> > userTweets;
    int globalTime;
    inline void initUser(int userId){
        if(feeds.find(userId) == feeds.end()) {
            feeds[userId] = deque<int>();
        }
        if(followers.find(userId) == followers.end()) {
            followers[userId] = unordered_set<int>();
            followers[userId].insert(userId);
        }
        if(userTweets.find(userId) == userTweets.end()) {
            userTweets[userId] = deque<int>();
        }
        if(following.find(userId) == following.end()) {
            following[userId] = unordered_set<int>();
            following[userId].insert(userId);
        }
        return;
    }

public:
    /** Initialize your data structure here. */
    Twitter() {
        globalTime = 1;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        printf("postTweet %d %d\n", userId, tweetId);
        assert(tweetOwner.find(tweetId) == tweetOwner.end());
        tweetOwner[tweetId] = userId;
        tweetTime[tweetId] = globalTime++;
        initUser(userId);
        userTweets[userId].push_front(tweetId);
        if(userTweets[userId].size() == 11) {
            userTweets[userId].pop_back();
        }
        printf("followers: ");
        for(auto i: followers[userId]) {
            printf("%d ",i);
            if(feeds[i].size()==10) {
                feeds[i].pop_back();
                feeds[i].push_front(tweetId);
            } else {
                feeds[i].push_front(tweetId);
            }
        }
        printf("\n");
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        printf("getNewsFeed\n");
        assert(feeds[userId].size() <= 10);
        return vector<int>(feeds[userId].begin(),feeds[userId].end());
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        printf("follow\n");
        if(followerId == followeeId) return;
        initUser(followerId);
        initUser(followeeId);
        if(followers[followeeId].find(followerId) != followers[followeeId].end()) return;
        followers[followeeId].insert(followerId);
        following[followerId].insert(followeeId);
        vector<int> tmp;
        auto it1 = feeds[followerId].begin();
        auto it2 = userTweets[followeeId].begin();
        while(tmp.size() < 10 && (it1 != feeds[followerId].end() || it2 != userTweets[followeeId].end() ) ) {
            if(it1 == feeds[followerId].end() || ( it2 != userTweets[followeeId].end()  && tweetTime[*it1] < tweetTime[*it2] )) {
                tmp.push_back(*it2);
                it2++;
            } else if(it2 == userTweets[followeeId].end() || ( it1 != feeds[followerId].end() && tweetTime[*it2] < tweetTime[*it1]) ) {
                tmp.push_back(*it1);
                it1++;
            } else assert(0);
        }
        feeds[followerId] = deque<int>(tmp.begin(), tmp.end());
        return;
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        printf("unfollow\n");
        if(followerId == followeeId) return;
        initUser(followerId);
        initUser(followeeId);
        if(followers[followeeId].find(followerId) == followers[followeeId].end()) return;
        vector<int> tmp;
        for(auto i: feeds[followerId]) {
            if(tweetOwner[i] != followeeId) {
                tmp.push_back(i);
            }
        }
        feeds[followerId] = deque<int>(tmp.begin(), tmp.end());
        following[followerId].erase(followeeId);
        followers[followeeId].erase(followerId);
        printf("got here\n");
        unordered_map<int,int> tmpIt;
        for(auto i: following[followerId]) tmpIt[i] = 0;
        while(feeds[followerId].size() < 10) {
            int findTime = 0;
            int ans = -1;
            for(auto i: following[followerId]) {
                
                while(userTweets[i].size() > tmpIt[i] && !feeds[followerId].empty() && tweetTime[userTweets[i][tmpIt[i]]] >= tweetTime[feeds[followerId].back()] ) tmpIt[i]++;
                if(userTweets[i].size() == tmpIt[i]) continue;
                if(tweetTime[userTweets[i][tmpIt[i]]] < max(findTime, feeds[followerId].empty()?0:tweetTime[feeds[followerId].back()] ) ) {
                    ans = userTweets[i][tmpIt[i]];
                    findTime = tweetTime[ans];
                }
            }
            if(!findTime) break;
            else {
                tmpIt[tweetOwner[ans]]++;
                feeds[followerId].push_back(ans);
            }
        }
        printf("got here2\n");
        return;
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