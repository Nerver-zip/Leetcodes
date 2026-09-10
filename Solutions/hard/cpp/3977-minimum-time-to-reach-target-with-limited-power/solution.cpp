using ll = long long;

class Solution {
using Graph = vector<vector<pair<int,int>>>;
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        Graph graph = buildGraph(n, edges);

        // distList[u][p] = minDist to reach node u having used p power
        vector<vector<ll>> distList(n, vector<ll>(power+1, LLONG_MAX));
        priority_queue<array<ll,3>, vector<array<ll,3>>, greater<>> minHeap; // {w, u, p}
        
        minHeap.push({0, source, 0});
        distList[source][0] = 0; 
        
        vector<ll> ans{LLONG_MAX,-1};

        while(!minHeap.empty()){
            auto [w, u, p] = minHeap.top();
            minHeap.pop();
            
            if(u == target){
                ans[1] = max(ans[1], power - p);
            }

            if(distList[u][p] < w){
                continue;
            }

            for(const auto& [v, t] : graph[u]){
                ll nw = w + t;
                ll newPower = p + cost[u];
                
                if(v == target){
                    ans[1] = max(ans[1], power - newPower);
                }

                if(newPower > power)
                    continue;
                
                if(distList[v][newPower] > nw){
                    distList[v][newPower] = nw;
                    minHeap.push({nw, v, newPower});
                }
            }
        }
        
        for(int p = 0; p <= power; ++p){
            if(ans[0] > distList[target][p]){
                ans[0] = distList[target][p];
                ans[1] = power - p;
            }
        }

        return ans[0] == LLONG_MAX ? vector<ll>{-1,-1} : ans;
    }
private:
    Graph buildGraph(int n, const vector<vector<int>>& edges){
        Graph g(n);

        for(const auto& edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];

            g[u].push_back({v, w});
        }

        return g;
    }
};