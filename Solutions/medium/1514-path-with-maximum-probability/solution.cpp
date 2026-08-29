#define Graph vector<vector<pair<int,double>>>
class Solution {
private:
    Graph buidGraph(int n, const vector<vector<int>>& edges, const vector<double>& succProb){
        Graph myGraph(n);
        int i = 0;
        for (const auto& edge : edges)
        {
            int src = edge[0];
            int tgt = edge[1];
            myGraph[src].push_back({tgt, succProb[i]});
            myGraph[tgt].push_back({src, succProb[i]});
            i++;
        }
        return myGraph;
    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        Graph graph = buidGraph(n, edges, succProb);
        vector<double> distList(n, -1.0);
        priority_queue<pair<double,int>, vector<pair<double,int>>> maxHeap; //prob, node
        maxHeap.push({1.0, start_node});
        distList[start_node] = 1.0;

        while (!maxHeap.empty())
        {
            auto [currProb, currNode] = maxHeap.top();
            maxHeap.pop();

            if (distList[currNode] > currProb) continue;
            
            for (const auto& [node, p] : graph[currNode])
            {
                double updatedProb = p * currProb;
                if (distList[node] < updatedProb)
                {
                    distList[node] = updatedProb;
                    maxHeap.push({updatedProb, node});
                }
            }
        }
        return distList[end_node] == -1.0 ? 0 : distList[end_node];
    }
};