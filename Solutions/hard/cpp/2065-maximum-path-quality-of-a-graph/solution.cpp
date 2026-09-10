template<typename T>
struct Edge {
    T v;
    int w;

    Edge(T v, int w) : v(v), w(w){} 
};

template<typename T>
using Graph = vector<vector<Edge<T>>>;

class Solution {
public:
    int ans = 0;
    vector<int> vals;
    Graph<int> graph;
    vector<int> visitCount;

    void dfs(int node, int remainingTime, int score){

        if(visitCount[node] == 0)
            score += vals[node];

        visitCount[node]++;

        if(node == 0)
            ans = max(ans, score);

        for(auto [v,w] : graph[node]){
            if(remainingTime >= w){
                dfs(v, remainingTime - w, score);
            }
        }

        visitCount[node]--;
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();

        graph = buildGraph(n, edges);
        vals = std::move(values);
        visitCount.resize(n);

        dfs(0, maxTime, 0);

        return ans;
    }
private:

    Graph<int> buildGraph(int n, const vector<vector<int>>& edges){
        Graph<int> graph(n);

        for(const auto& edge : edges){
            graph[edge[0]].push_back(Edge(edge[1], edge[2]));
            graph[edge[1]].push_back(Edge(edge[0], edge[2]));
        }

        return graph;
    }
};