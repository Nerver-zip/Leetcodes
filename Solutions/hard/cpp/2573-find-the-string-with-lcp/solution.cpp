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
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        // 1. validar diagonal
        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i) return "";
        }

        // 2. Union-Find
        UnionFind uf(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (lcp[i][j] > 0) {
                    uf.unite(i, j);
                }
            }
        }

        // 3. construir string (lexicograficamente mínima)
        vector<char> res(n);
        unordered_map<int, char> mp;
        char cur = 'a';

        for (int i = 0; i < n; i++) {
            int p = uf.find(i);

            if (!mp.count(p)) {
                if (cur > 'z') return "";
                mp[p] = cur++;
            }

            res[i] = mp[p];
        }

        string word(res.begin(), res.end());

        // 4. reconstruir LCP
        vector<vector<int>> check(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] == word[j]) {
                    if (i + 1 < n && j + 1 < n)
                        check[i][j] = check[i + 1][j + 1] + 1;
                    else
                        check[i][j] = 1;
                } else {
                    check[i][j] = 0;
                }
            }
        }

        // 5. validar
        if (check != lcp) return "";

        return word;
    }
};