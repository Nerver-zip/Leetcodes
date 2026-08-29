class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        const int n = graph.size();
        vector<vector<int>> ans;
        
        queue<pair<int, vector<int>>> q;
        vector<bool> visited(n);

        q.push({0, {}});
        visited[0] = true;

        while(!q.empty()){
            auto [u, list] = q.front();
            q.pop();
            
            list.push_back(u);

            if(list.back() == n-1)
                ans.push_back(list);

            for(const auto& v : graph[u]){
                visited[v] = true;
                q.push({v, list});
            }
        }
        
        return ans;
    }
};