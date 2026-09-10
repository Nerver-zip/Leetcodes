#define INFINITE LLONG_MAX
#define BOUND 1000000007
#define Graph vector<vector<pair<int,int>>>
class Solution {
private:
    Graph buildGraph(int n, const vector<vector<int>>& roads){
        Graph graph(n);
        for (const auto& road : roads)
        {
            graph[road[0]].push_back({road[1],road[2]});
            graph[road[1]].push_back({road[0],road[2]});
        }
        return graph;
    }
public:
    int countPaths(int n, vector<vector<int>>& roads) { //First, let's return shortest path to n-1;
        Graph graph = buildGraph(n, roads);
        vector<pair<long long,long long>> distList(n, pair<long long,long long>(LLONG_MAX,0)); //dist, number of ways
        
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, std::greater<>> nodeQueue; //dist, node
        nodeQueue.push({0,0});
        distList[0] = {0,1};

        while (!nodeQueue.empty())
        {
            auto [currDist, currNode] = nodeQueue.top();
            nodeQueue.pop();

            if (currDist > distList[currNode].first) continue;

            for (const auto& [neigh, cost] : graph[currNode])
            {
                long long updatedCost = cost + currDist;

                if (distList[neigh].first == updatedCost)
                    distList[neigh].second += distList[currNode].second % BOUND;

                else if (distList[neigh].first > updatedCost)
                {
                    distList[neigh].first = updatedCost;
                    distList[neigh].second = distList[currNode].second;
                    nodeQueue.push({updatedCost, neigh});
                }
            }
        }        
        return distList[n-1].second % BOUND;
    }
};