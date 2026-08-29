class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;
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

};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](auto &a, auto &b){ return a[2] < b[2]; });
        
        UnionFind uf(n);
        vector<bool> knows(n, false);
        knows[0] = knows[firstPerson] = true;
        
        int i = 0;
        while (i < meetings.size()) {
            int time = meetings[i][2];
            vector<pair<int,int>> current;
            
            // Coletar todas reuniões do mesmo tempo
            while (i < meetings.size() && meetings[i][2] == time) {
                current.push_back({meetings[i][0], meetings[i][1]});
                uf.unite(meetings[i][0], meetings[i][1]);
                i++;
            }
            
            // Descobrir quem tem o segredo nesse grupo
            unordered_map<int, vector<int>> groups;
            for (auto &p : current) {
                groups[uf.find(p.first)].push_back(p.first);
                groups[uf.find(p.second)].push_back(p.second);
            }
            
            for (auto &[rep, people] : groups) {
                bool has_secret = false;
                for (int person : people) 
                    if (knows[person]) 
                        has_secret = true;
                if (has_secret) {
                    for (int person : people) knows[person] = true;
                }
            }
            
            // Resetar UF para próximos tempos
            for (auto &p : current) {
                if (!knows[p.first]) 
                    uf.parent[p.first] = p.first;
                if (!knows[p.second]) 
                    uf.parent[p.second] = p.second;
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) 
            if (knows[i]) 
                ans.push_back(i);
        return ans;
    }
};
