class Solution {
using Graph = vector<vector<pair<int,int>>>;
public:
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        auto [graph, right] = buildGraph(n, edges);
        
        int left = 0;
        
        int ans = -1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            
            if(bfs(graph, source, target, k, mid)){
                ans = mid;
                right = mid-1;
            }
            else
                left = mid+1;
        }

        return ans;
    }
private:
    pair<Graph, int> buildGraph(int n, const vector<vector<int>>& edges){
        int maxEdge = 0;
        Graph g(n);

        for(const auto& edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            g[u].push_back({v,w});
            g[v].push_back({u,w});
            maxEdge = max(maxEdge, w);
        }

        return {g, maxEdge};
    }

    bool bfs(const Graph& g, int source, int tgt, int k, int threshold){
        const int n = g.size();
        deque<pair<int, int>> dq;
        vector<bool> visited(g.size());
        
        vector<int> dist(n, numeric_limits<int>::max());
        dist[source] = 0;
        dq.push_front({source, 0});
        
        while(!dq.empty()){
            auto [u, currCost] = dq.front();
            dq.pop_front();
            
            if(dist[tgt] <= k)
                return true;
            
            if(currCost > dist[u])
                continue;

            for (const auto& [v,w] : g[u]) {
                int cost = (w > threshold);

                if (currCost + cost < dist[v]) {
                    dist[v] = currCost + cost;
                    if (cost == 0)
                        dq.push_front({v, dist[v]});
                    else
                        dq.push_back({v, dist[v]});
                }
            }
        }
        
        return dist[tgt] <= k;
    }
};