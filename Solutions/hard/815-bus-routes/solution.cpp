class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> stopsToBus;

        for(int b = 0; b < routes.size(); ++b)
            for(int stop : routes[b]){
                stopsToBus[stop].push_back(b);
            }

        unordered_set<int> visitedStops, visitedBuses;

        queue<pair<int,int>> q;
        q.push({source, 0});
        visitedStops.insert(source);

        while (!q.empty()) {
            auto [currStop, busCount] = q.front();
            q.pop();

            if(currStop == target)
                return busCount;

            for(const auto& bus : stopsToBus[currStop]){
                if(!visitedBuses.count(bus)){
                    visitedBuses.insert(bus);
                    for(const auto& stop : routes[bus]){
                        if(!visitedStops.count(stop)){
                            visitedStops.insert(stop);
                            q.push({stop, busCount + 1});
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};