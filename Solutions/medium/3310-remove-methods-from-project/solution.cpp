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
    using Graph = vector<vector<int>>;
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        auto g = [&]()->Graph{
            Graph g(n);

            for(const auto& invocation : invocations){
                int u = invocation[0], v = invocation[1];

                g[u].push_back(v);
            }

            return g;
        }();

        UnionFind uf(n);
        
        auto bfs = [&](int u)->void{
            queue<int> q;
            vector<bool> visited(n);

            q.push(u);
            visited[u] = true;

            while(!q.empty()){
                int u = q.front();
                q.pop();

                for(int v : g[u]){
                    if(!visited[v]){
                        visited[v] = true;
                        uf.unite(u, v);
                        q.push(v);
                    }
                }
            }
        };

        bfs(k);
        
        vector<int> ans;
        ans.reserve(n);

        int pu_bug = uf.find(k); 
        
        for(int u = 0; u < n; ++u){
            if(uf.find(u) == pu_bug)
                continue;
            
            for(int v : g[u]){
                int pv_bug = uf.find(v);

                if(pv_bug == pu_bug)
                    goto no_remove; 
            }
            
            ans.push_back(u);
        }
        
        return ans;

        no_remove:
            ans.clear();
            ans.resize(n);            
            iota(ans.begin(), ans.end(), 0);
            return ans;
    }
};