#define Graph vector<vector<int>>
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        Graph graph(n);
        vector<int> inDegree(n, 0);
        
        // Build graph and in-degree
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            ++inDegree[edge[1]];
        }

        // Kahn's algorithm (topological sort)
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        vector<vector<int>> colorFreq(n, vector<int>(26, 0));
        int processed = 0;
        int maxColor = 0;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            ++processed;

            int colorIdx = colors[node] - 'a';
            colorFreq[node][colorIdx]++;
            maxColor = max(maxColor, colorFreq[node][colorIdx]);

            for (int neighbor : graph[node]) {
                for (int c = 0; c < 26; ++c) {
                    colorFreq[neighbor][c] = max(colorFreq[neighbor][c], colorFreq[node][c]);
                }
                if (--inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return processed == n ? maxColor : -1;
    }
};
