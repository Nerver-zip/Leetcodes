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
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        UnionFind uf(n);

        vector<bool> ans(requests.size());
        
        for(int i = 0; i < requests.size(); ++i){
            int u = requests[i][0], v = requests[i][1];
        
            int pu = uf.find(u), pv = uf.find(v); 
        
            for(const auto& r : restrictions){
                if(uf.find(r[0]) == pu && uf.find(r[1]) == pv ||
                   uf.find(r[1]) == pu && uf.find(r[0]) == pv)
                    goto end_loop;
            }
            
            uf.unite(u, v);
            ans[i] = true;

            end_loop:
        }
        
        return ans;
    }
};