#define Graph vector<vector<array<int,3>>>
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        auto buildGraph = [&](){
            Graph graph(n);

            for (const auto& edge : edges)
            {
                int u = edge[0], v = edge[1], start = edge[2], end = edge[3];
                graph[u].push_back({v, start, end});
            }
            return graph;
        };
        
        Graph graph = buildGraph();

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> minHeap; //{time, node}
        vector<int> timeToReach(n, INT32_MAX);

        minHeap.push({0,0});
        timeToReach[0] = 0;

        while (!minHeap.empty())
        {
            auto [currTime, currNode] = minHeap.top();
            minHeap.pop();

            if(timeToReach[currNode] < currTime)
                continue;
            
            for (const auto& [neigh, min, max] : graph[currNode])
            {
                int updatedTime = currTime;
                if (currTime < min)
                    updatedTime = min;
                else if (currTime > max)
                    continue;
                updatedTime += 1;
                if(timeToReach[neigh] > updatedTime)
                {
                    timeToReach[neigh] = updatedTime;
                    minHeap.push({updatedTime, neigh});
                }
            }
        }
        return timeToReach[n-1] == INT32_MAX ? -1 : timeToReach[n-1];
    }
};   