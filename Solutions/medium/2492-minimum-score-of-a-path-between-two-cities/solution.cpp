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

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        UnionFind uf(n + 1);

        for(const auto& edge : roads){
            uf.unite(edge[0], edge[1]);
        }
        
        int pv = uf.find(n);
        int ans = numeric_limits<int>::max();
        for(const auto& edge : roads){
            int pu = uf.find(edge[0]);
            int w = edge[2];

            if(pu == pv)
                ans = min(ans, w);

        }

        return ans;
    }
};