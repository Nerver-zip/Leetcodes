class UnionFind {
public:
    UnionFind(int size){
        parent.resize(size);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(size, 0);
    }
    
    int find(int x){
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    
    bool unite(int x, int y){
        int pX = find(x), pY = find(y);
        
        if(pX == pY)
            return false;
        
        if(rank[pX] > rank[pY])
            parent[pY] = pX;
        else if(rank[pX] < rank[pY])
            parent[pX] = pY;
        else {
            parent[pX] = pY;
            ++rank[pY];
        }
        return true;
    }
private:
    vector<int> parent;
    vector<int> rank;
};

constexpr array<pair<int,int>, 4> directions = {{
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
}};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        ROWS = row;
        COLS = col;

        UnionFind uf(row * col + 2);
        
        vector<bool> isLand(row * col + 2);
        isLand[0] = true;
        isLand[ROWS * COLS + 1] = true;  

        for (int i = cells.size()-1; i >= 0; --i) {
            int row = cells[i][0]-1, col = cells[i][1]-1;
            
            int idx = cellIndex(row, col);
            isLand[idx] = true;

            //Connect land to its neighs
            for (int i = 0; i < 4; ++i) {
                int newRow = row + directions[i].first, newCol = col + directions[i].second;
                if(isOutOfBounds(newCol))
                    continue;

                int new_idx;

                if(newRow < 0)
                    new_idx = 0;
                else if(newRow == ROWS)
                    new_idx = ROWS * COLS + 1;
                else
                    new_idx = cellIndex(newRow, newCol);
                
                if(!isLand[new_idx])
                    continue;
                
                uf.unite(idx, new_idx);
            }

            //Connection between top and bottom;
            if(uf.find(0) == uf.find(ROWS * COLS + 1))
                return i;
        }
        
        return -1;
    }
private:
    int ROWS, COLS;

    bool inline isOutOfBounds(int c){
        return c < 0 || c == COLS;
    }

    int inline cellIndex(int r, int c) const noexcept {
        return COLS * r + c + 1;
    }
};