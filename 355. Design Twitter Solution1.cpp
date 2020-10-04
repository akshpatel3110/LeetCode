class Twitter {
public:
    struct user {
        vector<pair<int, int>> tweets; // timestamp and tweet id
        unordered_set<int> follows;
    };
    
    struct tweet {
        int ts; // keyword in heap
        int tweet_id; // put to res
        int idx; // idx in tweets vector
        int user_id; // key for users hash map
        
        bool operator<(const tweet & rhs) const {
            return ts < rhs.ts;
        }
    };
    
    int ts; // tweets timestamp
    unordered_map<int, user> users; // user id to user struct
    
    /** Initialize your data structure here. */
    Twitter() :
        ts(0)
    {}
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        users[userId].tweets.emplace_back(ts++, tweetId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    // Time: O(10logn) where n is the number of followers for that user
    vector<int> getNewsFeed(int u) {
        priority_queue<tweet> heap;
        
        // initialize heap
        users[u].follows.insert(u);
        for (auto f : users[u].follows) {
            const auto & tweets = users[f].tweets;
            int n = tweets.size();
            if (n) {
                tweet t{tweets[n - 1].first, tweets[n - 1].second, n - 1, f};
                heap.push(move(t));
            }
        }
        
        // get res
        vector<int> res;
        for (int i = 0; i < 10 && heap.size(); ++i) {
            auto t = heap.top();
            heap.pop();
            res.push_back(t.tweet_id);
            if (t.idx) {
                auto & time_and_id = users[t.user_id].tweets[t.idx - 1];
                tweet nt{time_and_id.first, time_and_id.second, t.idx - 1, t.user_id};
                heap.push(move(nt));
            }
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int a, int b) {
        if (a != b)
            users[a].follows.insert(b);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int a, int b) {
        users[a].follows.erase(b);
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
