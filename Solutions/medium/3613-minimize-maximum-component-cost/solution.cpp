class UnionFind {
private:
    vector<int> rank;
    vector<pair<int,int>> parent;
    int groups;
public:
    UnionFind(int size){
        rank.assign(size, 0);
        parent.resize(size);
        groups = size;
        for(int i = 0; i < size; ++i)
            parent[i].first = i;
    }

    pair<int,int> find(int x){
        if(parent[x].first != x)
            parent[x] = find(parent[x].first);
        return parent[x];
    }

    bool unite(pair<int,int> x, pair<int,int> y, int cost){
        auto [rootX, costX] = find(x.first);
        auto [rootY, costY] = find(y.first);

        int maxCost = max(max(costX, costY), cost);

        if(rootX == rootY)
            return false;

        if(rank[rootX] < rank[rootY]){
            parent[rootX].first = rootY;
            parent[rootX].second = maxCost;
        }
        else if(rank[rootX] > rank[rootY]){
            parent[rootY].first = rootX;
            parent[rootY].second = maxCost;
        }
        else
        {
            parent[rootX].first = rootY;
            parent[rootY].second = maxCost;
            rank[rootY]++;
        }
        groups--;
        return true;
    }

    int getGroups(){
        return this->groups;
    }

    int maxCostMinimized(){
        int maxC = INT32_MIN;
        for (const auto& [_, cost] : parent)
            if(cost > maxC)
                maxC = cost;
        return maxC;
    }
};

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(), [](const auto& a, const auto& b){
            return a[2] < b[2];
        });

        UnionFind uf(n);

        int i = 0;
        while (uf.getGroups() > k && i < edges.size())
        {
            auto edge = edges[i];
            int u = edge[0], v = edge[1], w = edge[2];
            uf.unite({u,0},{v,0},w);
            ++i;
        }
        return uf.maxCostMinimized();
    }
};