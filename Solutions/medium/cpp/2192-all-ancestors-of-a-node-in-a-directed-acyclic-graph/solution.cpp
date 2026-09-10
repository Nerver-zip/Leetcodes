#define Graph vector<vector<int>>
class Solution {
private:
    Graph buildGraph(int n, const vector<vector<int>>& edges){
        Graph graph(n);

        for (const auto& edge : edges)
            graph[edge[0]].push_back(edge[1]);
        return graph;
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        Graph graph = buildGraph(n, edges);
        vector<int> inDegree(n, 0);
        queue<int> q;
        vector<unordered_set<int>> ancestors(n);
        vector<vector<int>> ans(n);

        for (const auto& node : graph)
            for (const auto& neigh : node)
                inDegree[neigh]++;

        for (int i = 0; i < n; ++i)
            if (inDegree[i] == 0)
                q.push(i);
            
        while (!q.empty())
        {
            auto currNode = q.front();
            q.pop();
    
            for (const auto& neigh : graph[currNode])
            {
                inDegree[neigh]--;
                ancestors[neigh].insert(currNode);
                for (const auto& ancestor : ancestors[currNode])
                    ancestors[neigh].insert(ancestor);

                if (inDegree[neigh] == 0)
                {                    
                   q.push(neigh);
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (const auto& ancestor : ancestors[i])
                ans[i].push_back(ancestor);
        }

        for (int i = 0; i < n; ++i)
            sort(ans[i].begin(), ans[i].end());
    
        return ans;
    }
};
