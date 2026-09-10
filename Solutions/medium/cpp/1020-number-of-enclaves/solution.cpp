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

    bool unite(int x, int y){
        int rootX = find(x);
        int rootY = find(y);

        if(rootX == rootY)
            return false;
        
        if(rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if(rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else
        {
            parent[rootX] = rootY;
            rank[rootY]++;
        }

        return true;
    }
};

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int reference = ROWS * COLS;

        auto getNode = [&](int r, int c){
            return COLS * r + c;
        };

        const vector<pair<int,int>> directions = {
            {0,1},
            {1,0}
        };
        
        UnionFind uf(ROWS * COLS + 1);

        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLS; ++j)
                if (grid[i][j] == 1)
                {
                    //link border 1 to reference
                    if(i == 0 || j == COLS-1 || i == ROWS-1 || j == 0)
                        uf.unite(getNode(i,j), reference);
                    for (const auto& [r, c] : directions)
                    {
                        int newRow = r + i;
                        int newCol = c + j;
                        if(newRow == ROWS || newCol == COLS || grid[newRow][newCol] == 0)
                            continue;
                        uf.unite(getNode(i, j) , getNode(newRow, newCol)); //link 1's
                    }
                }
        int ans = 0;
        const int ref = uf.find(reference);
        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLS; ++j)
                if(grid[i][j] == 1 && uf.find(getNode(i,j)) != ref)
                    ++ans; //1 is not linked to ref
        
        return ans;
    }
};