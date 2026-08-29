class Solution {
using Graph = vector<vector<pair<int,int>>>;
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        Graph graph = buildGraph(n, edges);
        vector<vector<int>> dist(n, vector<int>(k+1, numeric_limits<int>::max())); 
    
        priority_queue<array<int,4>, vector<array<int,4>>, greater<>> pq;
        pq.push({0, 0, labels[0], 1}); 
        dist[0][1] = 0;

        while(!pq.empty()){
            auto [currCost, u, last, consecutive] = pq.top();
            pq.pop();

            if(dist[u][consecutive] < currCost)
                continue;

            for(const auto& [v, w] : graph[u]){
                int newLabel = labels[v];
                int newCost = currCost + w;
                
                int newConsecutive = newLabel == last ? consecutive + 1 : 1;

                if(newConsecutive > k)
                    continue;
                
                if(dist[v][newConsecutive] > newCost){
                    dist[v][newConsecutive] = newCost;
                    pq.push({newCost, v, newLabel, newConsecutive});
                }

            }
        }
        
        int ans = numeric_limits<int>::max();

        for(int d : dist[n-1]){
            ans = min(ans, d);
        }

        return ans == numeric_limits<int>::max() ? -1 : ans;
    }
private:
    Graph buildGraph(int n, const vector<vector<int>>& edges){
        Graph g(n);

        for(const auto& edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            g[u].push_back({v,w});
        }

        return g;
    }
};