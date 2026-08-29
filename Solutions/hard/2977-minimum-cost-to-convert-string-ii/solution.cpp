class Solution {
public:
    static constexpr long long INF = 1e18;

    struct TrieNode {
        int next[26];
        // (changed_string, cost)
        vector<pair<string, long long>> outputs;
        TrieNode() {
            memset(next, -1, sizeof(next));
        }
    };

    vector<TrieNode> trie;

    void insertTrie(const string& orig, const string& chg, long long cost) {
        int node = 0;
        for (char c : orig) {
            int id = c - 'a';
            if (trie[node].next[id] == -1) {
                trie[node].next[id] = trie.size();
                trie.emplace_back();
            }
            node = trie[node].next[id];
        }
        trie[node].outputs.emplace_back(chg, cost);
    }

    long long minimumCost(
        string source,
        string target,
        vector<string>& original,
        vector<string>& changed,
        vector<int>& cost
    ) {
        int n = source.size();

        // coletar todas as strings
        unordered_map<string, int> id;
        vector<string> nodes;

        auto getId = [&](const string& s) {
            if (!id.count(s)) {
                id[s] = nodes.size();
                nodes.push_back(s);
            }
            return id[s];
        };

        for (int i = 0; i < original.size(); i++) {
            getId(original[i]);
            getId(changed[i]);
        }

        int m = nodes.size();

        // inicializar matriz de custos
        vector<vector<long long>> dist(m, vector<long long>(m, INF));
        for (int i = 0; i < m; i++)
            dist[i][i] = 0;

        for (int i = 0; i < original.size(); i++) {
            int u = id[original[i]];
            int v = id[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Floyd-Warshall
        for (int k = 0; k < m; k++)
            for (int i = 0; i < m; i++)
                for (int j = 0; j < m; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        // Trie
        trie.clear();
        trie.emplace_back();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i != j && dist[i][j] < INF) {
                    insertTrie(nodes[i], nodes[j], dist[i][j]);
                }
            }
        }

        // DP
        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            // opção: não fazer nada
            if (source[i] == target[i])
                dp[i] = dp[i + 1];

            int node = 0;
            for (int j = i; j < n; j++) {
                int idc = source[j] - 'a';
                if (trie[node].next[idc] == -1)
                    break;

                node = trie[node].next[idc];
                int len = j - i + 1;

                if (dp[i + len] == INF) continue;

                for (auto& [chg, c] : trie[node].outputs) {
                    if (i + chg.size() > n) continue;
                    if (target.compare(i, chg.size(), chg) == 0) {
                        dp[i] = min(dp[i], c + dp[i + len]);
                    }
                }
            }
        }

        return dp[0] == INF ? -1 : dp[0];
    }
};
