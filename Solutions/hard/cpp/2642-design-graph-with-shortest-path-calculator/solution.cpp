class Graph {
    using AdjList = vector<vector<pair<int,int>>>;
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        g.resize(n);

        for(const auto& edge : edges)
            g[edge[0]].push_back({edge[1],edge[2]});
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]].push_back({edge[1], edge[2]}); 
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int> distList(n, numeric_limits<int>::max());
        distList[node1] = 0;

        pq.push({0, node1});

        while (!pq.empty()) {
            auto [currDist, u] = pq.top();
            pq.pop();

            if(distList[u] < currDist)
                continue;

            for(const auto& [v, dist] : g[u]){
                int updatedDist = currDist + dist;
                if(distList[v] > updatedDist){
                    distList[v] = updatedDist;
                    pq.push({updatedDist, v});
                }
            }
        }

        return distList[node2] == numeric_limits<int>::max() ? -1 : distList[node2];
    }
private:
    AdjList g;
    int n;
};
/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */