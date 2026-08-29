class Solution {
private:
    std::unordered_map<int,bool> safe;

    bool dfs(vector<vector<int>>& edges, int node){
        if (safe.find(node) != safe.end())
        {
            return safe[node];
        }
        safe[node] = false;
        for (const auto& neighbor : edges[node])
        {
            if (!dfs(edges,neighbor))
            {
                return false;
            }
        }
        safe[node] = true;
        return true;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> nodeList;

        for (int i = 0; i < graph.size(); i++)
        {
            if (dfs(graph, i))
            {
                nodeList.push_back(i); 
            }
        }
        return nodeList;
    }
};