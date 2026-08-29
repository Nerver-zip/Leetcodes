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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> edgeCount(n, 0);
        unordered_map<int,vector<int>> map;

        UnionFind uf(n);

        for(const auto& edge : edges){
            int u = edge[0], v = edge[1];

            ++edgeCount[u];
            ++edgeCount[v];

            uf.unite(u, v);
        }
        
        for(int u = 0; u < n; ++u){
            int pu = uf.find(u);
            map[pu].push_back(u);
        }
        
        int ans = 0;
        
        for(const auto& [_, list] : map){
            for(int u : list){
                if(edgeCount[u] != list.size() - 1)
                    goto end;
            }

            ++ans;
            end:
        }

        return ans;
    }
};