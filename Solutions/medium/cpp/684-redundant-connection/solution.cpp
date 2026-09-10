class Solution {
private:
    bool unionAlgo(int n1, int n2,vector<int>& parent, vector<int>& rank){
        int p1 = find(n1,parent);
        int p2 = find(n2,parent);
        if (p1==p2)
            return false;

        if (rank[p1] > rank[p2]){
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }

        else{
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }

    int find(int n, vector<int>& parent){
        if (n != parent[n]){
            parent[n] = find(parent[n],parent);
        }
        return parent[n];
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent;

        for (int i = 0; i < edges.size()+1; i++)
        {
            parent.push_back(i);
        }

        vector<int> rank(edges.size()+1,1);

        for (const auto& node : edges)
        {
            if(!unionAlgo(node[0],node[1],parent,rank))
                return {node[0],node[1]};
        }
         
        return {};
    }
};