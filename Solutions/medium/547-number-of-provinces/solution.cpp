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
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        const int size = isConnected.size();
        UnionFind uf(size);

        for (int u = 0; u < size; ++u)
            for (int v = 0; v < size; ++v)
                if(u != v && isConnected[u][v])
                    uf.unite(u, v);
            
        unordered_set<int> provinces;

        for (int u = 0; u < size; ++u)
            provinces.insert(uf.find(u));
        
        return provinces.size();        
    }
};
