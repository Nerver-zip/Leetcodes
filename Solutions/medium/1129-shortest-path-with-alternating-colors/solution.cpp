class Solution {

using Graph = vector<vector<pair<int,int>>>; 
    
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    
        Graph g = buildGraph(n, redEdges, blueEdges);
        vector<int> distList(n, numeric_limits<int>::max());
        
        // u -> {RED, BLUE}
        // we can visit nodes coming from blue or red
        // we need to cuttoff cycles when they already explored both options
        vector<vector<bool>> visited (n, vector<bool>(2, false));

        queue<array<int, 3>> q; // {u, dist, color}
        q.push({0, 0, NOCOLOR});
        distList[0] = 0;
        
        while(!q.empty()){
            auto [u, currDist, lastColor] = q.front();
            q.pop();
            
            distList[u] = min(currDist, distList[u]);

            for (const auto& [v, color] : g[u]) {
                int newDist = currDist + 1;
                
                if(lastColor != RED && color == RED && !visited[v][RED]){
                    visited[v][RED] = true;
                    q.push({v, newDist, RED});
                }
                   
                if(lastColor != BLUE && color == BLUE && !visited[v][BLUE]){
                    visited[v][BLUE] = true;
                    q.push({v, newDist, BLUE});
                }
            }

        }

        for(int& d : distList)
            if(d == numeric_limits<int>::max())
                d = -1;

        return distList;
    }

private:
    enum Colors {
        RED,
        BLUE,
        NOCOLOR
    };

    Graph buildGraph(int n, const vector<vector<int>>& redEdges, const vector<vector<int>>& blueEdges){
        Graph graph(n);

        for(const auto& edge : redEdges)
            graph[edge[0]].push_back({edge[1], RED});


        for(const auto& edge : blueEdges)
            graph[edge[0]].push_back({edge[1], BLUE});

        return graph;
    }
};