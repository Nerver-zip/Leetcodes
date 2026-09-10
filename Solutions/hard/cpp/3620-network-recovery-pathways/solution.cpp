using ll = long long;

class Solution {
using Graph = vector<vector<pair<int,int>>>;
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        auto graph = buildGraph(edges, online, online.size());
        
        ll left = 0, right = k;
        
        int ans = -1;
        while(left <= right){
            ll mid = left + (right - left)/2;

            if(check(graph, mid, k)){
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;

            }
        }

        return ans;
    }

private:
    Graph buildGraph(const vector<vector<int>>& edges, const vector<bool>& online, int n){
        Graph g(n);

        for(const auto& edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            
            if(online[u] && online[v])
                g[u].push_back({v,w});
        }

        return g;
    }

    bool check(const Graph& g, int minWeight, ll k){
        const int n = g.size();

        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
        vector<ll> distList(n, numeric_limits<ll>::max());

        distList[0] = 0;
        pq.push({0,0});

        while(!pq.empty()){
            auto [uw, u] = pq.top();
            pq.pop();

            if(distList[u] < uw)
                continue;

            for(const auto& [v, vw] : g[u]){
                if(vw >= minWeight && uw + vw <= k){
                    ll nw = 1LL * uw + vw;
                    
                    if(distList[v] > nw){
                        distList[v] = nw;
                        pq.push({nw, v});
                    }
                }
            }
        }

        return distList[n-1] == numeric_limits<ll>::max() ? false : true; 
    }
};