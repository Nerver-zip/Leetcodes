#define INFINITE 100000000
struct Compare {
    bool operator()(const array<int,3>& a, const array<int,3>& b) const {
        return a[0] > b[0]; //Min heap sorted by first element
    }
};

class Solution {
private:
    vector<vector<std::pair<int,int>>> buildGraph(const vector<vector<int>>& flights, int size){
        vector<vector<std::pair<int,int>>> myGraph(size);

        for (const auto& flight : flights)
        {
            int src = flight[0];
            int tgt = flight[1];
            int cost = flight[2];

            myGraph[src].push_back({tgt,cost});
        }
        return myGraph;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<std::pair<int,int>>> graph = buildGraph(flights, n);
        vector<int> costList(n,INFINITE);
        vector<int> stopList(n,INFINITE); //min stops to get to certain node

        std::priority_queue<array<int,3>, vector<array<int,3>>, Compare> minHeap; //{cost, node, stops}
        minHeap.push({0,src,0});
        costList[src] = 0;

        while (!minHeap.empty())
        {
            auto values = minHeap.top();
            minHeap.pop();
            int currCost = values[0];
            int currNode = values[1];
            int currStops = values[2];

            if(currCost > costList[currNode] && stopList[currNode] <= currStops || currStops > k) continue;
            stopList[currNode] = std::min(stopList[currNode], currStops);

            for (const auto& [neigh, cost] : graph[currNode])
            {
                int updCost = cost + currCost;
                if (costList[neigh] > updCost || stopList[neigh] > currStops + 1)
                {
                    costList[neigh] = std::min(updCost,costList[neigh]);
                    minHeap.push({updCost, neigh, currStops + 1});
                }
            }
        }
        return costList[dst] == INFINITE ? -1 : costList[dst];         
    }
};