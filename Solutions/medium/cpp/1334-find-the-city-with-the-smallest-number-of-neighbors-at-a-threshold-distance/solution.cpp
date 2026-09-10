class Solution {
    using Graph = vector<vector<pair<int,int>>>;
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const auto graph = buildGraph(edges, n);
        
        vector<vector<int>> distances(n);

        for(int i = 0; i < n; ++i)
            distances[i] = shortesPath(graph, i);
        

        vector<int> reachable(n, 0);

        for(int city = 0; city < n; ++city){
            for(int v = 0; v < n; ++v){
                if(city == v) continue;

                if(distances[city][v] <= distanceThreshold)
                    ++reachable[city];
            }
        }

        int minReachable = numeric_limits<int>::max(), ans = 0;
        for(int city = 0; city < n; ++city){
            if(reachable[city] <= minReachable){
                ans = city;
                minReachable = reachable[city];
            }
        }

        return ans;
    }
private:
    vector<int> shortesPath(const Graph& g, int src){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int> distList(g.size(), numeric_limits<int>::max());
        distList[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [currDist, u] = pq.top();
            pq.pop();

            if(distList[u] < currDist)
                continue;

            for(const auto& [v, w] : g[u]){
                int updatedDist = w + currDist;
                if(distList[v] > updatedDist){
                    distList[v] = updatedDist;
                    pq.push({updatedDist, v});
                }
            }
        }

        return distList;
    }

    Graph buildGraph(const vector<vector<int>>& edges, int n){
        Graph g(n);

        for(const auto& edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];

            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }

        return g;
    }
};