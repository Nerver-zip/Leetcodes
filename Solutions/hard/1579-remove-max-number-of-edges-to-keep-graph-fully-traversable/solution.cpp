class UnionFind {
private:
    vector<int> rank;
    vector<int> parent;
    int components;
public:
    //1-indexed
    UnionFind(int size){
        rank.assign(size + 1, 0);
        parent.resize(size + 1);
        components = size; 
        for(int i = 1; i <= size; ++i)
            parent[i] = i;
    }

    int find(int x){
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y){
        if(components == 1)
            return false;

        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return false;
        
        if(rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if(rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else
        {
            parent[rootX] = rootY;
            rank[rootY]++;
        }
        --components;
        return true;
    }

    bool isFullyConnected(){
        return components == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        //Solving in three steps, first type 3 edges, then Bob's edges and then Alice's edges 
        sort(edges.begin(), edges.end(), [](const auto& edgeA, const auto& edgeB){
            return edgeA[0] > edgeB[0];
        });

        UnionFind bob(n), alice(n);
        int used = 0;

        for (const auto& edge : edges)
        {
            if(bob.isFullyConnected() && alice.isFullyConnected())
                return edges.size() - used;
            if(edge[0] == 3)
            {
                bool aliceAdded = alice.unite(edge[1], edge[2]);
                bool bobAdded = bob.unite(edge[1], edge[2]);
                if(aliceAdded || bobAdded)
                    ++used;
            }
            else if(edge[0] == 2){
                if(bob.unite(edge[1], edge[2]))
                    ++used;
            }
            else    
               if(alice.unite(edge[1], edge[2]))
                    ++used;
        }
        return bob.isFullyConnected() && alice.isFullyConnected() ? edges.size() - used : -1;
    }
};