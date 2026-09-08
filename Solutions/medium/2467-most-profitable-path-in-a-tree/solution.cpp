#define INF_MIN -100000000
#define INF_MAX 100000000
class Solution {
private:
void bobsPath(const vector<vector<int>>& edges, int bob, vector<int>& time, int N) {
    vector<vector<int>> adjList = constructAdjListInverted(edges, N);
    vector<int> parent(N, -1); 
    vector<bool> visited(N, false);
    std::queue<std::pair<int, int>> q;
    
    q.push({bob, 0});
    visited[bob] = true;
    time[bob] = 0;
    
    while (!q.empty()) {
        auto [node, t] = q.front();
        q.pop();
    
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                time[neighbor] = t + 1;  
                q.push({neighbor, t + 1});
            }
        }
    }
    vector<pair<int, int>> pathWithTime;
    int curr = 0;
    
    while (curr != -1) {
        pathWithTime.push_back({curr, time[curr]});
        curr = parent[curr];
    }

    std::fill(time.begin(), time.end(), INF_MAX);
    for (const auto& path : pathWithTime) {
        time[path.first] = path.second;
    }
}
    vector<vector<int>> constructAdjListInverted(const vector<vector<int>>& edges, int N){
        vector<vector<int>> adjList(N);
            
            for (const auto& direction : edges)
            {
                int src = direction[0];
                int tgt = direction[1];
                adjList[tgt].push_back(src);
                adjList[src].push_back(tgt);
            }
            return adjList;
    }

    vector<vector<int>> constructAdjList(const vector<vector<int>>& edges, int N, vector<int>& leaveMap){
        vector<vector<int>> adjList(N);
        leaveMap.assign(N, 0);
            for (const auto& direction : edges)
            {   
                int src = direction[0];
                int tgt = direction[1];
                leaveMap[src]++;
                leaveMap[tgt]++;
                adjList[src].push_back(tgt);
                adjList[tgt].push_back(src);
            }
            return adjList;
    }

    void dfs(const vector<vector<int>>& graph, const vector<int>& bobsPath, const vector<int>& amount, vector<bool>& visited,
        int source, const vector<int>& leaveMap,int time, int& profit, int currProfit, int root){
        
        if (bobsPath[source] > time)
        {
            currProfit += amount[source];
        }
        else if (bobsPath[source] == time)
        {
            currProfit += (amount[source]/2);
        }
        
        if (root != source && leaveMap[source] == 1)
        {   
            profit = std::max(profit,currProfit);
        }
        
        visited[source] = true;
        for (const auto& neighbors : graph[source])
        {
            if (visited[neighbors])
            {
                continue;
            }
            dfs(graph,bobsPath,amount,visited,neighbors,leaveMap,time+1,profit,currProfit,0);
        }
        return;
    }
    
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int N = amount.size();
        vector<int> bobTime(N,INF_MAX);
        bobsPath(edges,bob,bobTime,N);

        vector<int> leaveMap;
        vector<vector<int>> adjList = constructAdjList(edges, N, leaveMap);
        vector<vector<int>>().swap(edges);
        vector<bool> visited(N);
    
        int profits = INF_MIN;

        dfs(adjList,bobTime,amount,visited,0,leaveMap,0,profits,0,0);
        
        return profits;
    }
};