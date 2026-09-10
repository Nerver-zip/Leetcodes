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
        else{
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
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        const int ROWS = grid1.size();
        const int COLS = grid1[0].size();
        unordered_set<int> bannedIslands;

        auto getNode = [&](int row, int col){
            return COLS * row + col; 
        };

        vector<pair<int,int>> directions = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };

        UnionFind uf(ROWS * COLS); //on grid2

        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLS; ++j)
                if(grid2[i][j])
                    for (const auto& [r, c] : directions)
                    {
                        int newRow = r + i;
                        int newCol = c + j;

                        if(isLand(grid2, newRow, newCol, ROWS, COLS))
                            uf.unite(getNode(i, j), getNode(newRow, newCol));
                    }

        unordered_set<int> islands;

        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLS; ++j)
                if(grid1[i][j] == 0)
                    bannedIslands.insert(uf.find(getNode(i,j)));
                else if(grid2[i][j])
                    islands.insert(uf.find(getNode(i,j)));

        int ans = islands.size();
        
        for(const auto& island : islands)
            if(bannedIslands.count(island))
                ans--;
        return ans;
    }
};