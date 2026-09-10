using ll = long long;

using Graph = vector<vector<int>>;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        auto buildGraph = [&](){
            Graph graph(26, vector<int>(26, INT32_MAX));
            
            for (int i = 0; i < original.size(); ++i) {
                int& curr = graph[original[i] - 'a'][changed[i] - 'a'];
                curr = min(curr, cost[i]);
            }

            return graph;
        };
        
        Graph graph = buildGraph();
        
        auto shortestPath = [&graph](char source, char target){
            vector<int> costs(26, INT32_MAX);

            priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>> minHeap;
            costs[source - 'a'] = 0;
            minHeap.push({0, source});
            
            while (!minHeap.empty()) {
                auto [currCost, currChar] = minHeap.top();
                minHeap.pop();

                if(currCost > costs[currChar - 'a'])
                    continue;

                for(int i = 0; i < 26; ++i){
                    if(graph[currChar - 'a'][i] == INT32_MAX)
                        continue;

                    int newCost = currCost + graph[currChar - 'a'][i];

                    if(costs[i] > newCost){
                        costs[i] = newCost;
                        minHeap.push({newCost, i + 'a'});
                    }
                }
            }
            return costs[target - 'a'];
        };
        
        ll totalCost = 0;
        vector<vector<int>> conversionCosts(26, vector<int>(26, -1));
        for (int i = 0; i < source.size(); ++i) {
            char src = source[i], tgt = target[i];
            
            int& c_cost = conversionCosts[src - 'a'][tgt - 'a'];
            if(c_cost == -1){
                int cost = shortestPath(src, tgt);
                if(cost == INT32_MAX)
                    return -1;
                c_cost = cost;
            }
            
            totalCost += c_cost;
        }

        return totalCost;
    }
};