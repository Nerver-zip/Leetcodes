class UnionFind{
public:
    UnionFind(int size){
        parent.resize(size);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(size, 0);
    }

    int find(int x){
        while(parent[x] != x)
            x = parent[x] = parent[parent[x]];
        return x;
    }

    bool unite(int x, int y){
        int pX = find(x), pY = find(y);

        if(pX == pY)
            return false;

        if(rank[pX] < rank[pY])
            parent[pX] = pY;
        else if (rank[pX] > rank[pY])
            parent[pY] = pX;
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
    int longestConsecutive(vector<int>& nums) {
        const int size = nums.size();
        unordered_map<int,int> map;

        for(int i = 0; i < size; ++i)
            map[nums[i]] = i;
        
        int count = 1;

        UnionFind uf(size);
        for(const auto& [val, idx] : map){
            auto it_l = map.find(val-1);
            auto it_r = map.find(val+1);

            if(it_l != map.end())
                uf.unite(idx, it_l->second);
            if(it_r != map.end())
                uf.unite(idx, it_r->second);
        }
        
        int ans = 0;
        unordered_map<int, int> freq;
        for(const auto& [_, idx] : map){
            int& f = freq[uf.find(idx)];
            ans = max(ans, ++f);
        }

        return ans;
    }
};