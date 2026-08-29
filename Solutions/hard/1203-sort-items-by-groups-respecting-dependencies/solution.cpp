#define Graph vector<vector<int>> 

using namespace std;
class Solution {
private:
    Graph buildItemGraph(const vector<vector<int>>& edges, vector<int>& inDegree, int n){
        Graph graph(n);
        for (int v = 0; v < n; ++v)
            for (int u = 0; u < edges[v].size(); ++u)
            {
                graph[edges[v][u]].push_back(v);
                inDegree[v]++;
            }
        return graph;
    }

    Graph buildGroupGraph(const vector<int>& groups, const vector<vector<int>>& edges, vector<int>& inDegree, int m){
        Graph graph(m);
        unordered_set<string> added;
        for (int v = 0; v < groups.size(); ++v)
            for (int u = 0; u < edges[v].size(); ++u)
            {   
                if (groups[edges[v][u]] == groups[v])
                    continue;
                
                string key = to_string(groups[edges[v][u]]) + "," + to_string(groups[v]);

                if (added.count(key))
                    continue;

                graph[groups[edges[v][u]]].push_back(groups[v]);
                inDegree[groups[v]]++;
                added.insert(key);
            }
        return graph;
    }

    vector<int> topologicalSort(const Graph& graph, vector<int>& inDegree, int n){
        queue<int> q;
        vector<int> sorted;

        for (int i = 0; i < n; ++i)
            if(inDegree[i] == 0)
                q.push(i);

        while (!q.empty())
        {
            auto currNode = q.front();
            q.pop();

            sorted.push_back(currNode);

            for (const auto& neigh : graph[currNode])
            {
                inDegree[neigh]--;
                if (inDegree[neigh] == 0)
                    q.push(neigh);
            }
        }
        return sorted.size() == n ? sorted : vector<int>();       
    }

public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        //No group is the same thing as a group with a single element
        int totalGroups = m;
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1)
                group[i] = totalGroups++;
        }

        vector<int> inDegreeItems(n, 0);
        vector<int> inDegreeGroups(totalGroups, 0);
        Graph itemGraph = buildItemGraph(beforeItems, inDegreeItems, n);
        Graph groupGraph = buildGroupGraph(group, beforeItems, inDegreeGroups, totalGroups);

        vector<int> items = topologicalSort(itemGraph, inDegreeItems, n);
        vector<int> groups = topologicalSort(groupGraph, inDegreeGroups, totalGroups);

        if (items.size() == 0 || groups.size() == 0)
            return {};
        
        unordered_map<int, vector<int>> groupMap;

        for (int item : items)
            groupMap[group[item]].push_back(item);
        
        vector<int> ans;

        for (int g : groups)
            for (int item : groupMap[g])
                ans.push_back(item);
                
        return ans;
    }
};
