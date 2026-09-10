class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        auto buildGraph = [&edges, &n](){
            vector<vector<int>> graph(n);

            for(const auto& edge : edges){
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            }

            return graph;
        };

        auto graph = buildGraph();
        
        queue<int> q;
        vector<bool> visited(n);
        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            if(u == destination)
                return true;

            for(const auto& v : graph[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }

        return false;
    }
};