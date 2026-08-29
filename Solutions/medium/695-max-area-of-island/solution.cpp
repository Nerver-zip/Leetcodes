class UnionFind {
private:
    vector<int> rank;
    vector<int> parent;
public:
    UnionFind(int size){
        rank.assign(size, 0);
        parent.resize(size);

        for (int i = 0; i < size; ++i)
            parent[i] = i;
    }

    int find(int x){
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y){
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return;
        
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if(rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else
        {
            parent[rootX] = rootY;
            rank[rootY]++;
        }
    }
};

class Solution {
private:
    bool isLand(const vector<vector<int>>& grid, int r, int c, int ROWS, int COLS){
        return r < 0 || c < 0 || r == ROWS || c == COLS || grid[r][c] == 0 ? false : true;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const vector<pair<int,int>> directions {
            {0, 1},
            {0,-1},
            {1, 0},
            {-1, 0}
        };
        
        UnionFind uf(ROWS * COLS);
        unordered_map<int, int> islandMap;

        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLS; ++j)
                if(grid[i][j])
                    for (const auto& [r, c] : directions)
                    {
                        int newRow = r + i;
                        int newCol = c + j;

                        //converting grid to N - 1 nodes
                        int u = (COLS * i) + j; 
                        int v = (COLS * newRow) + newCol;

                        if (isLand(grid, newRow, newCol, ROWS, COLS))
                            uf.unite(u, v);
                    }

        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLS; ++j)
                if(grid[i][j]){
                    int u = (COLS * i) + j; 
                    islandMap[uf.find(u)]++;
                }
        int ans = 0;
        for (const auto& [island, area] : islandMap)
            ans = max(ans, area);
        return ans;
    }
};
