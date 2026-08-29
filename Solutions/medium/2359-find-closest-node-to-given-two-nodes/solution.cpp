#define Graph vector<vector<int>>
class Solution {
private:
    vector<int> shortestPaths(const vector<int>& edges, const int node, const int size){
        vector<int> distanceList(size, INT32_MAX);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        minHeap.push({0, node});
        distanceList[node] = 0;

        while (!minHeap.empty())
        {
            auto [currDist, currNode] = minHeap.top();
            minHeap.pop();
        
            if(distanceList[currNode] < currDist)
                continue;
            
            auto neigh = edges[currNode];
            if (neigh != -1)
            {
                int updatedDist = currDist + 1;
                if (distanceList[neigh] > updatedDist)
                {
                    distanceList[neigh] = updatedDist;
                    minHeap.push({updatedDist, neigh});
                }
            }
        }
        return distanceList;
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int size = edges.size();
        vector<int> distancesNode1 = shortestPaths(edges, node1, size);
        vector<int> distancesNode2 = shortestPaths(edges, node2, size);

        int maxMinDist = INT32_MAX;
        int maxCurr;
        int ans = -1;
        for (int i = 0; i < size; ++i)
        {
            if (distancesNode1[i] != INT32_MAX && distancesNode2[i] != INT32_MAX)
            {
                maxCurr = max(distancesNode1[i], distancesNode2[i]);
                if (maxCurr < maxMinDist)
                {
                    maxMinDist = maxCurr;
                    ans = i;
                }
            }
        }
        return ans;
    }
};