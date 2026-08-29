class UnionFind {
private:
    vector<int> rank;
    vector<int> parent;
public:
    UnionFind(int size){
        rank.assign(size, 0);
        parent.resize(size);
        
        for(int i = 0; i < size; ++i)
            parent[i] = i;
    }

    int find(int x){
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y){
        int rootX = find(x);
        int rootY = find(y);

        if(rootX == rootY)
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

        return true;
    }
};

class Solution {
public:
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    const int n = accounts.size();
    UnionFind uf(n);

    unordered_map<string, int> email_to_id;

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < accounts[i].size(); ++j) {
            const string& email = accounts[i][j];
            if (email_to_id.count(email)) {
                uf.unite(i, email_to_id[email]);
            } else {
                email_to_id[email] = i;
            }
        }
    }

    unordered_map<int, unordered_set<string>> groups;
    for (const auto& [email, idx] : email_to_id) {
        int root = uf.find(idx);
        groups[root].insert(email);
    }

    vector<vector<string>> ans;
    for (auto& [root, emails] : groups) {
        vector<string> merged;
        merged.push_back(accounts[root][0]);
        merged.insert(merged.end(), emails.begin(), emails.end());
        sort(merged.begin() + 1, merged.end());
        ans.push_back(merged);
    }
    return ans;
}
};