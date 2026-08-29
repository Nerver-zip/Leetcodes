#define Graph vector<vector<pair<int,int>>>
class Solution {
private:
    Graph buildGraph(const vector<vector<int>>& grid, const vector<vector<int>>& moveCost, const int size){
        Graph graph(size);

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
            {
                graph[grid[i][j]] = neighbors(grid, i, j, moveCost);
            }
        return graph;
    }

    vector<pair<int,int>> neighbors(const vector<vector<int>>& grid, int i, int j, const vector<vector<int>>& moveCost){
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        vector<pair<int,int>> neighs;
        int k = i+1;
        if(k < ROWS)
            for (int l = 0; l < COLS; ++l)
                neighs.push_back({grid[k][l], moveCost[grid[i][j]][l]});
        return neighs;
    }

public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        const int size = grid.size() * grid[0].size();
        Graph graph = buildGraph(grid, moveCost, size);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        int minimum = INT32_MAX;

        for (int i = 0; i < grid[0].size(); i++)
        {
            vector<int> distanceList(size, INT32_MAX);
            minHeap.push({grid[0][i], grid[0][i]});
            distanceList[grid[0][i]] = grid[0][i];

            while (!minHeap.empty())
            {
                auto [currDistance, currNode] = minHeap.top();
                minHeap.pop();

                if (distanceList[currNode] < currDistance)
                    continue;
                
                for (const auto& [neigh, cost] : graph[currNode])
                {
                    int updatedDist = currDistance + neigh + cost;
                    if (distanceList[neigh] > updatedDist)
                    {
                        distanceList[neigh] = updatedDist;
                        minHeap.push({updatedDist, neigh});
                    }
                }
                int lastRow = grid.size()-1;
                for (int j = 0; j < grid[0].size(); ++j)
                    minimum = min(distanceList[grid[lastRow][j]], minimum);
            }
        }
        return minimum;
    }

    void printGraph(vector<vector<int>>& grid, vector<vector<int>>& moveCost){
        const int size = grid.size() * grid[0].size();
        Graph graph = buildGraph(grid, moveCost, size);
        for (int i = 0; i < graph.size(); ++i)
        {
            for (const auto& neigh : graph[i])
            {
                cout << "Node: " << i << "-> " << neigh.first << " Cost: " << neigh.second  << "\n"; 
            }
            cout << "\n";
        }
    }
};