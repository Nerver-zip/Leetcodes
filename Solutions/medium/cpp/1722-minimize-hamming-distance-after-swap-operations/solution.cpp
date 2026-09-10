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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        const int n = source.size();

        UnionFind uf(n);
        
        // connect components in source based on allowed swaps
        // saving indexes

        for(const auto& swap : allowedSwaps){
            int u = swap[0], v = swap[1];
            uf.unite(u, v);
        }

        
        unordered_map<int, vector<int>> components;

        for(int i = 0; i < n; ++i){
            int key = uf.find(i);
            components[key].push_back(i);
        }
        
        // now check differs from the connected components with target
        
        int ans = 0;
        for(const auto& [_, component] : components){
            unordered_map<int, int> freq;

            for(int i : component)
                ++freq[source[i]];
            
            for(int i : component)
                if(freq[target[i]]){ // use ocurrance
                    --freq[target[i]];
                }
                else // if we can't this pos must contribute to Hamming dist
                    ++ans;
        }

        return ans;
    }
};