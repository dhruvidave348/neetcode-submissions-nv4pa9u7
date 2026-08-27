class Twitter {
private:
    int time = 0;

    unordered_map<int, unordered_set<int>> following;

    unordered_map<int, vector<pair<int, int>>> tweets;

public:

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<
            tuple<int, int, int, int>
        > pq;

        // Include yourself
        following[userId].insert(userId);

        // Put the latest tweet of every followed user into heap
        for (int followee : following[userId]) {

            if (!tweets[followee].empty()) {

                int index = tweets[followee].size() - 1;

                auto [timestamp, tweetId] = tweets[followee][index];

                pq.push({
                    timestamp,
                    followee,
                    index,
                    tweetId
                });
            }
        }

        vector<int> result;

        // Get 10 newest tweets
        while (!pq.empty() && result.size() < 10) {

            auto [timestamp, user, index, tweetId] = pq.top();

            pq.pop();

            result.push_back(tweetId);

            // Move to previous tweet of same user
            if (index > 0) {

                index--;

                auto [newTime, newTweetId] =
                    tweets[user][index];

                pq.push({
                    newTime,
                    user,
                    index,
                    newTweetId
                });
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        if (followerId != followeeId) {
            following[followerId].erase(followeeId);
        }
    }
};