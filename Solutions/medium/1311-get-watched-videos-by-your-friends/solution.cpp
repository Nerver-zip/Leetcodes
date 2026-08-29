class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        vector<int> dist(n, INT_MAX);

        dfs(id, 0, friends, dist);

        unordered_map<string,int> freq;

        for (int i = 0; i < n; i++) {
            if (dist[i] == level) {
                for (auto& v : watchedVideos[i]) {
                    freq[v]++;
                }
            }
        }

        vector<string> ans;
        for (auto& [v, _] : freq)
            ans.push_back(v);

        sort(ans.begin(), ans.end(), [&](const string& a, const string& b){
            if (freq[a] != freq[b])
                return freq[a] < freq[b];
            return a < b;
        });

        return ans;
    }
private:
    void dfs(int u, int d,
             const vector<vector<int>>& friends,
             vector<int>& dist) {

        if (d >= dist[u]) return;

        dist[u] = d;

        for (int v : friends[u]) {
            dfs(v, d + 1, friends, dist);
        }
    }
};