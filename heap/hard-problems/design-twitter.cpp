#include <bits/stdc++.h>
using namespace std;
class Twitter
{
private:
    int time;
    struct Tweet
    {
        int tweet_id;
        int twt_time;
        // prev as of previous tweet of the user before this tweet
        Tweet *prev_twt;
        Tweet(int tweet_id, int twt_time) : tweet_id(tweet_id), twt_time(twt_time), prev_twt(nullptr) {};
        Tweet(int tweet_id, int twt_time, Tweet *prev_twt) : tweet_id(tweet_id), twt_time(twt_time), prev_twt(prev_twt) {};
    };
    unordered_map<int, Tweet *> tweet_db;
    unordered_map<int, unordered_set<int>> follow_db;
    struct Tweet_Comparator
    {
        bool operator()(const Tweet *a, const Tweet *b) const
        {
            // max heap, tweet with highest time goes on top
            return a->twt_time < b->twt_time;
        }
    };

public:
    Twitter() : time(0) {}

    void postTweet(int user_id, int tweet_id)
    {
        // first tweet of the user
        if (tweet_db.find(user_id) == tweet_db.end())
        {
            Tweet *twt = new Tweet(tweet_id, time);
            tweet_db.insert({user_id, twt});
        }
        else
        {
            Tweet *most_recent_twt = tweet_db.at(user_id);
            Tweet *current_twt = new Tweet(tweet_id, time, most_recent_twt);
            tweet_db.at(user_id) = current_twt;
        }
        time++;
    }

    vector<int> getNewsFeed(int user_id)
    {
        unordered_set<int> feed_users;
        if (follow_db.find(user_id) != follow_db.end())
        {
            feed_users = follow_db.at(user_id);
        }
        feed_users.insert(user_id);

        int lim = 10;
        vector<Tweet *> twt_strms;
        twt_strms.reserve(feed_users.size());
        for (const int &usr : feed_users)
        {
            // Only push to twt_strms if the user has tweeted anything
            if (tweet_db.find(usr) != tweet_db.end())
            {
                twt_strms.push_back(tweet_db.at(usr));
            }
        }
        priority_queue<Tweet *, vector<Tweet *>, Tweet_Comparator> pq;
        for (const auto twt : twt_strms)
        {
            pq.push(twt);
        }
        vector<int> feed;
        while (!pq.empty())
        {
            Tweet *twt = pq.top();
            pq.pop();
            if (lim > 0)
            {
                feed.push_back(twt->tweet_id);
                lim--;
            }
            else
            {
                break;
            }
            if (twt->prev_twt != nullptr)
            {
                pq.push(twt->prev_twt);
            }
        }
        return feed;
    }

    void follow(int follower_id, int followee_id)
    {
        if (follow_db.find(follower_id) == follow_db.end())
        {
            follow_db.insert({follower_id, {followee_id}});
        }
        else
        {
            follow_db.at(follower_id).insert(followee_id);
        }
    }

    void unfollow(int follower_id, int followee_id)
    {
        // if user follows some one and the followee is present in user's followee list
        if (follow_db.find(follower_id) != follow_db.end() && follow_db.at(follower_id).find(followee_id) != follow_db.at(follower_id).end())
        {
            follow_db.at(follower_id).erase(followee_id);
            // if there is no one remaining that user follows delete the user's entry as well
            if (follow_db.at(follower_id).empty())
            {
                follow_db.erase(follower_id);
            }
        }
    }

    // delete all tweets before exiting to prevent memory leak
    ~Twitter()
    {
        for (auto it : tweet_db)
        {
            Tweet *most_recent_twt = it.second;
            while (most_recent_twt != nullptr)
            {
                Tweet *prev_twt = most_recent_twt->prev_twt;
                delete most_recent_twt;
                most_recent_twt = prev_twt;
            }
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
int main()
{
    // putting twitter object in heap becuase this object can be heavy
    Twitter *twtr = new Twitter();
    // * 1: post twt
    // * 2: follow
    // * 3: unfollow
    vector<vector<int>> activity = {{1, 5, 1}, {2, 3, 1}, {1, 2, 2}, {1, 101, 1}, {3, 13, 1}, {2, 3, 2}, {3, 2, 2}, {1, 10, 1}, {4, 1, 2}, {2, 2, 1}, {4, 94, 1}, {1, 505, 1}, {2, 1, 3}, {3, 333, 1}, {1, 22, 1}, {2, 11, 1}, {4, 3, 3}};
    for (const auto &it : activity)
    {
        switch (it[2])
        {
        case 1:
            twtr->postTweet(it[0], it[1]);
            break;
        case 2:
            twtr->follow(it[0], it[1]);
        case 3:
            twtr->unfollow(it[0], it[1]);
        default:
            break;
        }
    }
    for (int i = 1; i < 5; i++)
    {
        cout << "news feed for user " << i << "\n";
        for (const int &twt_id : twtr->getNewsFeed(i))
        {
            cout << twt_id << ", ";
        }
        cout << endl;
    }
    // delete twtr object
    delete twtr;
    return 0;
}