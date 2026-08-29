#define INFINITE 1000000000
#define Graph vector<vector<std::pair<int,int>>>
class Solution {
private:
    Graph buildGraph(const vector<vector<int>>& edges, int n){
        Graph myGraph(n);
        for (const auto& edge : edges)
        {
            int src = edge[0];
            int tgt = edge[1];
            int cost = edge[2];

            myGraph[src].push_back({tgt, cost});
            myGraph[tgt].push_back({src, cost});
        }
        return myGraph;
    }

    void bfs(const Graph& graph, vector<int>& componentID, vector<int>& componentCost, vector<bool>& visited, int node, int id){
        std::queue<int> nodeQueue; //node, cost
        std::unordered_set<int> paths;
        nodeQueue.push(node);
        componentID[node] = id;

        int min = INFINITE;
        //Finds min path between connected components going through every path
        while (!nodeQueue.empty())
        {
            int currNode = nodeQueue.front();
            nodeQueue.pop();
            for (const auto& [neigh, cost] : graph[currNode])
            {
                if (visited[neigh] && paths.find(cost) != paths.end()) continue;
                min = min == INFINITE ? cost : min & cost;
                paths.insert(cost);
                componentID[neigh] = id;
                visited[neigh] = true;
                nodeQueue.push(neigh);
            }
        }
        componentCost[id] = (min == INFINITE) ? -1 : min;
    }

public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        Graph graph = buildGraph(edges, n);
        vector<bool> visited(n);
        vector<int> componentID(n, -1);
        vector<int> componentCost(n, -1);

        vector<int> ans;
        int id = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                bfs(graph, componentID, componentCost, visited, i, id);
                id++;
            }
        }
        
        for (const auto& q : query)
        {
            int src = q[0];
            int tgt = q[1];
            
            if (componentID[src] != componentID[tgt])
                ans.push_back(-1);
            else
                ans.push_back(componentCost[componentID[src]]);
        }        
        return ans;
    }
};