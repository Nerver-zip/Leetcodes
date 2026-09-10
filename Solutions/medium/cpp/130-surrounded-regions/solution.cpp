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
        else{
            parent[rootX] = rootY;
            rank[rootY]++;
        }

        return true;
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int ROWS = board.size();
        const int COLS = board[0].size();
        const int size = ROWS * COLS;

        const auto getNode = [&](int r, int c){
            return COLS * r + c;
        };

        const auto getPosition = [&](int n){
            return pair<int,int> (n/COLS, n % COLS);
        };

        const vector<pair<int,int>> directions = {
            {0,1},
            {1,0},
            {0,-1},
            {-1,0}
        };

        const auto isOutOfBounds = [&](int r, int c){
            return r == ROWS || c == COLS || r < 0 || c < 0;
        }; 

        UnionFind uf(size + 1);
        //Group all 'O'
        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLS; ++j)
                if(board[i][j] == 'X')
                    uf.unite(getNode(i,j), size);
                else
                    for (int k = 0; k < 2; ++k)
                    {
                        int newRow = i + directions[k].first, newCol = j + directions[k].second;
                        if(newRow == ROWS || newCol == COLS || board[newRow][newCol] != 'O')
                            continue;
                        uf.unite(getNode(i,j), getNode(newRow, newCol));
                    }
        //Only set group to 'X' if neither element is in the border
        //Map groups and iterate them

        const int xRoot = uf.find(size);
        unordered_map<int, unordered_set<int>> nodeMap;
        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLS; ++j){
                int node = getNode(i,j);
                int group = uf.find(node);
                if(group != xRoot)
                    nodeMap[group].insert(node);
            }
        
        unordered_set<int> toDelete;
        bool del;
        for (const auto& [group, set] : nodeMap)
        {
            del = true;
            for (const auto& node : set)
            {
                if(!del)
                    break;
                for (const auto& [r, c] : directions)
                {
                    auto pos = getPosition(node);
                    int newRow = pos.first + r, newCol = pos.second + c;

                    if(isOutOfBounds(newRow, newCol)){
                        del = false;
                        break;
                    }
                }
            }
            if(del)
                toDelete.insert(group);
        }
        
        if (toDelete.size() > 0)
        {
            for (int i = 0; i < ROWS; ++i)
                for (int j = 0; j < COLS; ++j)
                    if(toDelete.find(uf.find(getNode(i,j))) != toDelete.end())
                        board[i][j] = 'X';
        }
    }
};
