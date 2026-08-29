class UnionFind {
private:
    vector<int> rank;
    vector<int> parent;
    int groups;
public:
    UnionFind(int size){
        groups = size;
        rank.assign(size, 0);
        parent.resize(size, 0);

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
        groups--;
    }

    int componentAmount(){
        return groups;
    }

};

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        UnionFind uf(n);
        for (const auto& edge : edges)
            uf.unite(edge[0], edge[1]);
                
        if(k - uf.componentAmount() <= 0)
            return 0;

        uf = UnionFind(n);
        sort(edges.begin(), edges.end(), [](const auto& a, const auto& b){
            return a[2] < b[2];
        });
        
        int t = 0;
        int i = edges.size()-1; 

        while (uf.componentAmount() >= k && i >= 0) {
            uf.unite(edges[i][0], edges[i][1]);
            t = edges[i][2];
            --i;
        }
        return t;
    }
};
