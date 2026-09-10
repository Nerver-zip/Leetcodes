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

class Solution {
private:
    bool isValid(const vector<vector<int>>& matrix, int r, int c, int size){
        return r < 0 || c < 0 || r == size || c == size || matrix[r][c] == 1 ? false : true;
    }
public:
    int regionsBySlashes(vector<string>& grid) {        
        const int N = grid.size();
        const int N_TOTAL = N * 3;
        vector<vector<int>> matrix(N_TOTAL, vector<int>(N_TOTAL, 0));
        UnionFind uf(N_TOTAL * N_TOTAL);

        auto getNode = [&](int r, int c){
            return N_TOTAL * r + c;
        };

        auto build = [&](int r, int c, char t){
            if(t == '\\')
                for(int i = 0; i < 3; ++i)
                    matrix[r+i][c+i] = 1;
            else if(t == '/')
            {
                int row = r + 2;
                for (int i = 0; i < 3; ++i)
                    matrix[row--][c++] = 1;
            }
        };
        
        vector<pair<int,int>> directions = {
            {0,1},
            {1,0},
        };
        
        int row = 0;
        for (int i = 0; i < N; ++i) {
            int col = 0;
            for (int j = 0; j < N; ++j) {
                build(row, col, grid[i][j]);
                col += 3;
            }
            row += 3;
        }

        for (int i = 0; i < N_TOTAL; ++i)
            for (int j = 0; j < N_TOTAL; ++j)
                if(matrix[i][j] == 0)
                    for (const auto& [r, c] : directions){
                        int newRow = r + i;
                        int newCol = c + j;
                        if(isValid(matrix, newRow, newCol, N_TOTAL))
                            uf.unite(getNode(i,j), getNode(newRow, newCol));
                    }
                    
        unordered_set<int> regions;
        for (int i = 0; i < N_TOTAL; ++i)
            for (int j = 0; j < N_TOTAL; ++j)
                if(matrix[i][j] == 0)
                    regions.insert(uf.find(getNode(i,j)));
            
        return regions.size();
    }
};
