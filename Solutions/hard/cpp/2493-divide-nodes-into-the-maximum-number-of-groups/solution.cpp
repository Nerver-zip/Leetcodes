class Solution {
private:
    std::unordered_set<int> getConnectedComponent(int src, std::unordered_set<int>& visited, std::unordered_map<int, vector<int>>& adj) {
        std::deque<int> myQueue;
        std::unordered_set<int> component;
        myQueue.push_back(src);
        visited.insert(src);
        component.insert(src);

        while (!myQueue.empty()) {
            int node = myQueue.front();
            myQueue.pop_front();
            
            for (const auto& nei : adj[node]) {
                if (visited.find(nei) != visited.end())
                    continue;
                myQueue.push_back(nei);
                component.insert(nei);
                visited.insert(nei);
            }
        }
        return component;
    }

    int longestPath(int src, std::unordered_map<int, vector<int>>& adj) {
        std::deque<std::pair<int, int>> myQueue;
        std::unordered_map<int, int> dist;

        myQueue.push_back({src, 1});
        dist[src] = 1;
        int max_val = 1;

        while (!myQueue.empty()) {
            auto [node, length] = myQueue.front();
            myQueue.pop_front();

            for (int nei : adj[node]) {
                if (dist.find(nei) != dist.end()) {
                    if (dist[nei] == length) { 
                        return -1;
                    }
                    continue;
                }
                myQueue.push_back({nei, length + 1});
                dist[nei] = length + 1;
                max_val = std::max(max_val, length + 1); 
            }
        }
        return max_val;
    }

public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        std::unordered_map<int, vector<int>> adj;

        
        for (const auto& edge : edges) {
            int n1 = edge[0], n2 = edge[1];
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }

        std::unordered_set<int> visited;
        int res = 0;

        for (int i = 1; i <= n; i++) {
            if (visited.find(i) != visited.end())
                continue;

            std::unordered_set<int> component = getConnectedComponent(i, visited, adj);
            int max_count = 0;

            for (const auto& src : component) {
                int length = longestPath(src, adj);
                if (length == -1) 
                    return -1;
                max_count = std::max(max_count, length);
            }
            res += max_count;
        }
        return res;
    }
};