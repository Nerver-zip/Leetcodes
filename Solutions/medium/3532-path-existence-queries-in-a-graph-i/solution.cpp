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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        UnionFind uf(n);

        for(int left = 0, right = 0; right < n; ++right){

            while(nums[right] - nums[left] > maxDiff){
                ++left;
            }

            uf.unite(left, right);
        }
        
        vector<bool> ans;
        ans.reserve(n);

        for(const auto& q : queries){
            int u = q[0], v = q[1];
            
            if(uf.find(u) == uf.find(v))
                ans.push_back(true);
            else
                ans.push_back(false);
        }

        return ans;
    }
};