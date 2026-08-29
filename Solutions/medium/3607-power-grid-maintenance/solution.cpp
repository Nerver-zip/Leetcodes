class UnionFind {
public:
    UnionFind(int size){
        parent.resize(size);
        rank.assign(size, 0);
        this->size = size;

        for(int i = 1; i < size; ++i)
            parent[i] = i;
    }

    int find(int x){
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    bool unite(int x, int y){
        int rootX = find(x), rootY = find(y);

        if(rootX == rootY)
            return false;

        if(rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else if(rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else{
            parent[rootX] = rootY;
            ++rank[rootY];
        }
        return true;
    }

    void build(){
        for (int i = 1; i < size; ++i){
            int p = find(i);
            group[p].insert(i);
        }
    }

    void removeStation(int x){
        int pX = find(x);
        group[pX].erase(x);
    }

    int maintenanceCheck(int x){
        int pX = find(x);
        if(group[pX].count(x))
            return x;
        
        auto it = group[pX].cbegin();

        return it == group[pX].end() ? -1 : *it;
    }

private:
    vector<int> parent, rank;
    unordered_map<int, set<int>> group;
    int size, count;
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        auto uf = UnionFind(c + 1);

        for (const auto& connection : connections) {
            int u = connection[0], v = connection[1];
            uf.unite(u, v);
        }
        
        uf.build();
        
        vector<int> ans;

        for (const auto& query : queries) {
            int operation = query[0], station = query[1];

            if(operation == 1)
                ans.push_back(uf.maintenanceCheck(station));
            else
                uf.removeStation(station);
        }

        return ans;
    }
};
