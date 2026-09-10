//u -> {neighbor, cost, reversed edge(0 false, 1 true)}
using Graph = vector<vector<pair<int,int>>>;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {

        vector<int> dist(n, INT32_MAX);
        
        Graph graph = buildGraph(n, edges);
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare<int>> minHeap;
        
        dist[0] = 0;
        minHeap.push({0,0});

        while (!minHeap.empty()) {
            auto [u, currCost] = minHeap.top();
            minHeap.pop();

            if(dist[u] < currCost)
                continue;

            for (const auto& [v, w] : graph[u]) {
                int newCost = currCost + w;

                if(newCost < dist[v]){
                    dist[v] = newCost;
                    minHeap.push({v, newCost});
                }
            }
        }
        
        return dist[n-1] == INT32_MAX ? -1 : dist[n-1];
    }
private:
    
    Graph buildGraph(int n, const vector<vector<int>>& edges){
        Graph graph(n);
        
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w*2});
        }
        
        return graph;
    }
    
    template<typename T>
    struct Compare {
        bool operator()(const pair<T,T>& a, const pair<T,T>& b) const {
            return a.second > b.second;
        }
    };
};