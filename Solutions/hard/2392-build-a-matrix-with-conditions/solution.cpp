#define Graph vector<vector<int>>
class Solution {
private:
    /**
     * @brief Build an adjacency list
     *
     * @param k number of nodes
     * @param edges to sort by dependencies
     * @param inDegree this function already initializes inDegree
     * @returns an adjacencyList with inDegree initialized
     */
    Graph buildGraph(int k, const vector<vector<int>>& edges, vector<int>& inDegree){
        Graph graph(k+1);
        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        return graph;
    }

    vector<int> topoSort(const Graph& graph, vector<int>& inDegree){
        queue<int> q;
        vector<int> sorted;

        for (int i = 1; i < graph.size(); ++i)
            if (inDegree[i] == 0)
                q.push(i);
        
        while (!q.empty())
        {
            auto currNode = q.front();
            q.pop();

            sorted.push_back(currNode);

            for (const auto& neigh : graph[currNode])
            {
                inDegree[neigh]--;
                if (inDegree[neigh] == 0)
                    q.push(neigh);
            }
        }
        return sorted.size() != graph.size() - 1 ? vector<int>() : sorted;   
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> inDegree(k+1);
        Graph graph = buildGraph(k, rowConditions, inDegree);
        vector<int> sortedRow = topoSort(graph, inDegree);

        fill(inDegree.begin(), inDegree.end(), 0);
        graph = buildGraph(k, colConditions, inDegree);
        vector<int> sortedCol = topoSort(graph, inDegree);

        if (sortedRow.size() == 0 || sortedCol.size() == 0)
            return {};  

        vector<vector<int>> ans(k, vector<int>(k, 0));
        
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < k; ++j)
                if (sortedRow[i] == sortedCol[j])
                    ans[i][j] = sortedRow[i];
                
        return ans;
    }    
};