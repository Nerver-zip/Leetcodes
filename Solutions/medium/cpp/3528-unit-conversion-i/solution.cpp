#define MODULO 1000000007
#define Graph vector<vector<pair<int,int>>>
class Solution {
private:
    Graph buildGraph(const vector<vector<int>>& conversions){
        int size = conversions.size()+1;
        Graph graph(size);

        for (const auto& conversion : conversions)
        {
            int src = conversion[0];
            int tgt = conversion[1];
            int factor = conversion[2];
            graph[src].push_back({tgt, factor});
        }
        return graph;
    }
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        Graph graph = buildGraph(conversions);
        queue<pair<long, long>> q; //node, factor
        vector<int> baseUnitArray(graph.size(), -1);

        q.push({0,1});

        while (!q.empty())
        {
            auto [currNode, currFactor] = q.front();
            q.pop();

            baseUnitArray[currNode] = currFactor;

            for (const auto& [node, factor] : graph[currNode])
            {
                int newFactor = (currFactor * factor) % MODULO;
                q.push({node, newFactor}); 
            }
        }
        return baseUnitArray;
    }
};