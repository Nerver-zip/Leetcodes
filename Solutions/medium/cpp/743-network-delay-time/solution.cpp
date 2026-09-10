class Solution {

using Graph = vector<vector<pair<int,int>>>;

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const auto graph = buildGraph(times, n+1);
        vector<int> distList(n+1, numeric_limits<int>::max());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap; // time, u
        minHeap.push({0,k});
        distList[k] = 0;
        
        while (!minHeap.empty()) {
            auto [currTime, u] = minHeap.top();
            minHeap.pop();

            if(distList[u] < currTime)
                continue;

            for(const auto& [v, time] : graph[u]){
                int updatedTime = currTime + time;
                if(distList[v] > updatedTime){
                    distList[v] = updatedTime;
                    minHeap.push({updatedTime, v});
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; ++i)
            ans = max(ans, distList[i]);
    
        return ans == numeric_limits<int>::max() ? -1 : ans;
    }
private:
    Graph buildGraph(const vector<vector<int>>& edges, int n){
        Graph g(n);

        for(const auto& edge : edges)
            g[edge[0]].push_back({edge[1], edge[2]});
        
        return g;
    }
};