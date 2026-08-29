#define Graph vector<vector<int>>
class Solution {
private:
    Graph buildGraph(const vector<vector<int>>& edges, int n){
        Graph graph(n+1);

        for (const auto& edge : edges)
            graph[edge[0]].push_back(edge[1]);

        return graph;
    }
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        Graph graph = buildGraph(relations, n);
        vector<int> inDegree(n+1, 0);
        vector<int> minimumTime(n+1, 0);
        queue<pair<int,int>> q;

        for (const auto& node : graph)
            for (const auto& neigh : node)
                inDegree[neigh]++;
        
        for (int i = 1; i <= n; ++i)
            if(inDegree[i] == 0)
                q.push({i, time[i-1]});

        int maxTime = 0;

        while (!q.empty())
        {
            auto [currNode, currTime] = q.front();
            q.pop();

            maxTime = max(currTime, maxTime);

            for (const auto& neigh : graph[currNode])
            {
                inDegree[neigh]--;
                minimumTime[neigh] = max(minimumTime[neigh], currTime);   
                if (inDegree[neigh] == 0)
                    q.push({neigh, minimumTime[neigh] + time[neigh-1]});
            }
        }
        return maxTime;
    }
};