#define Graph vector<vector<int>>
struct Compare
{
    bool operator()(const array<int, 3>& a, const array<int, 3>& b) const {
        return a[0] > b[0]; //sort min heap by first element in array
    }
};

class Solution {
private:
    int getTotalTime(int stops, int transitionTime, int change){
        int totalTime = 0;

        for (int i = 0; i < stops; i++)
        {
            totalTime += transitionTime;

            //if the number of changes is odd, signal is red
            if ((totalTime/change) % 2 == 1 && i < stops-1)
            {
                //get time spent while in red to offset
                int offset = totalTime % change;
                totalTime += change - offset;
            }
        }
        return totalTime;
    }

    Graph buildGraph(const int n, const vector<vector<int>>& edges){
        Graph graph(n);
        for (const auto& edge : edges)
        {
            graph[edge[0]-1].push_back(edge[1]-1);
            graph[edge[1]-1].push_back(edge[0]-1);
        }
        return graph;
    }
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        Graph graph = buildGraph(n, edges);
        priority_queue<array<int, 3>, vector<array<int,3>>, Compare> minHeap; //{time, node, stops}
        vector<int> timeList1(n, INT32_MAX);
        vector<int> timeList2(n, INT32_MAX);
        vector<int> stops1(n, 0);
        vector<int> stops2(n, 0);
        
        minHeap.push({0,0,0});
        timeList1[0] = 0;

        while (!minHeap.empty())
        {
            auto [currTime, currNode, currStops] = minHeap.top();
            minHeap.pop();
            
            if(timeList2[currNode] < currTime)
                continue;

            for (const auto& neigh : graph[currNode])
            {
                int updatedTime = currTime + time;

                if (updatedTime < timeList1[neigh])
                {
                    timeList2[neigh] = timeList1[neigh];
                    stops2[neigh] = stops1[neigh];

                    timeList1[neigh] = updatedTime;
                    stops1[neigh] = currStops + 1;
                    minHeap.push({updatedTime, neigh, currStops + 1}); 
                }
                else if(updatedTime < timeList2[neigh] && updatedTime > timeList1[neigh]){
                    timeList2[neigh] = updatedTime;
                    stops2[neigh] = currStops + 1;
                    minHeap.push({updatedTime, neigh, currStops + 1});
                }
            }
        }
        return getTotalTime(stops2[n-1], time, change);
    }
};