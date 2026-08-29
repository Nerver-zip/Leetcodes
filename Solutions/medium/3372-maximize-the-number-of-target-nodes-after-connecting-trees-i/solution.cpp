#define Graph vector<vector<int>>
//Compute max number of nodes reachable within k paths in first tree for each node
//Compute max number of nodes reachable within k-1 paths in second tree for each node
//To answer the i query (initilized for k reachable as of first tree), compute maxPaths1[i] += max(maxPaths2.begin, maxPaths2.end)
class Solution {
private:
    Graph buildGraph(const vector<vector<int>>& edges, int size){
        Graph tree(size);

        for (const auto& edge : edges)
        {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        return tree;
    }

    void dfs(const Graph& tree, vector<bool>& visited, int node, int accum, int& total, int k){
        visited[node] = true;
        if(accum <= k)
            ++total;
        for (const auto& neigh : tree[node])
        {
            if (!visited[neigh] && accum < k)
            {
                dfs(tree, visited, neigh, accum + 1, total, k);
            }    
        }
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int size1 = edges1.size() + 1;
        Graph tree1 = buildGraph(edges1, size1);
        vector<int> nodes1(size1, 0);

        for (int i = 0; i < size1; ++i)
        {
            vector<bool> visited(size1);
            dfs(tree1, visited, i, 0, nodes1[i], k);
        }

        int size2 = edges2.size() + 1;
        Graph tree2 = buildGraph(edges2, size2);
        vector<int> nodes2(size2, 0);

        int maxNodesSecond = 0;
        for (int i = 0; i < size2; ++i)
        {
            vector<bool> visited(size2);
            dfs(tree2, visited, i, 0, nodes2[i], k-1); //discount extra edge since we're adding one
            maxNodesSecond = max(maxNodesSecond, nodes2[i]);
        }
        
        for (int i = 0; i < size1; ++i)
            nodes1[i] += maxNodesSecond;
        
        return nodes1;
    }
};
