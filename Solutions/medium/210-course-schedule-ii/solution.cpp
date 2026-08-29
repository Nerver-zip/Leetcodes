#define Graph vector<vector<int>>
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        Graph graph(numCourses);
        vector<int> inDegree(numCourses);


        for (const auto& edge : prerequisites) //must take edge[1] before edge[0]
        {
            graph[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if(inDegree[i] == 0)
                q.push(i);
        
        vector<int> ans;
        while (!q.empty())
        {
            auto currNode = q.front();
            q.pop();

            ans.push_back(currNode);

            for (const auto& neigh : graph[currNode])
            {
                inDegree[neigh]--;
                if (inDegree[neigh] == 0)
                    q.push(neigh);
            }
        }
        return ans.size() != numCourses ? vector<int>() : ans;
    }
};