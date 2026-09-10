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
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(),[](const auto& a, const auto& b){
           return a[2] > b[2];
        });
        
        vector<vector<int>> mustInclude;
        int maxW = 0;
        for(const auto& edge : edges){
            if(edge[3])
                mustInclude.push_back(edge);
            maxW = max(maxW, edge[2]);
        }

        auto check = [&](int stability) -> bool {
            UnionFind uf(n);
            int included = 0;

            vector<int> mustWeights;
            vector<int> upgradeableWeights;

            // adicionar must edges
            for(const auto& edge : mustInclude){
                if(!uf.unite(edge[0], edge[1]))
                    return false;

                mustWeights.push_back(edge[2]);
                ++included;

                if(included > n-1)
                    return false;
            }

            // completar MST
            for(const auto& edge : edges){
                
                if(uf.unite(edge[0], edge[1])){
                    upgradeableWeights.push_back(edge[2]);
                    ++included;
                }

                if(included == n-1)
                    break;
            }

            if(included != n-1)
                return false;

            // aplicar upgrades nas menores elegíveis
            sort(upgradeableWeights.begin(), upgradeableWeights.end());

            int upgrades = min(k, (int)upgradeableWeights.size());
            for(int i = 0; i < upgrades; i++)
                upgradeableWeights[i] *= 2;

            // calcular estabilidade
            int minEdge = INT_MAX;

            for(int w : mustWeights)
                minEdge = min(minEdge, w);

            for(int w : upgradeableWeights)
                minEdge = min(minEdge, w);

            return minEdge >= stability;
        };
        
        int ans = -1;
        int left = 0, right = maxW*2;
        
        while(left <= right){
            int mid = left + (right - left)/2;

            if(check(mid)){
                ans = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        
        return ans;
    }
};