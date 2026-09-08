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

        if(rootX == rootY)
            return;
        
        if(rank[rootX] < rank[rootY])
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
    bool isLand(const vector<vector<char>>& grid, int r, int c, int ROWS, int COLS){
        return r < 0 || c < 0 || r == ROWS || c == COLS || grid[r][c] == '0' ? false : true;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        auto getNode = [&](int row, int col){
            return (COLS * row) + col; 
        };

        const vector<pair<int,int>> directions{
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };

        UnionFind uf(ROWS * COLS);

        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLS; ++j)
                if(grid[i][j] == '1')
                    for (const auto& [r, c] : directions){
                        int newRow = r + i;
                        int newCol = c + j;
                        if(isLand(grid, newRow, newCol, ROWS, COLS))
                            uf.unite(getNode(i,j), getNode(newRow, newCol));
                    }

        unordered_set<int> islands;
        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLS; ++j)
                if(grid[i][j] == '1')
                    islands.insert(uf.find(getNode(i,j)));
            
        return islands.size();
    }
};