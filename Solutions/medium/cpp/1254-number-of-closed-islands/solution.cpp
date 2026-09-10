class UnionFind {
private:
    vector<int> rank;
    vector<int> parent;
public:
    UnionFind(int size){
        rank.assign(size, 0);
        parent.resize(size);

        for(int i = 0; i < size; ++i)
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


//Group islands, and verify how many of them share connection with 'outOfBounds'
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int size = ROWS * COLS;

        auto getNode = [&](int r, int c){
            return COLS * r + c;
        };

        auto isOutOfBounds = [&](int r, int c){
            return r < 0 || c < 0 || r == ROWS || c == COLS;
        };

        vector<pair<int,int>> directions = {
            {0,1},
            {1,0},
            {0,-1},
            {-1,0}
        };

        UnionFind uf(size + 1); //Extra node to represent OutOfBounds

        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLS; ++j)
                if(grid[i][j] == 0)
                    for(int k = 0; k < 4; ++k){
                        int newRow = i + directions[k].first;
                        int newCol = j + directions[k].second;

                        if(isOutOfBounds(newRow, newCol))
                            uf.unite(getNode(i, j), size);
                        else if(grid[newRow][newCol] == 0)
                            uf.unite(getNode(i, j), getNode(newRow, newCol));
                    }
        
        unordered_set<int> islands;
        const int reference = uf.find(size);

        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLS; ++j)
                if(grid[i][j] == 0){
                    int currGroup = uf.find(getNode(i,j));
                    if(currGroup != reference)
                        islands.insert(currGroup);

                }
            
        return islands.size();
    }
};
