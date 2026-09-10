class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> seen;

        for(const auto& edge : edges)
            seen.insert(edge[1]);
        
        vector<int> ans;
        for(int i = 0; i < n; ++i)
            if(!seen.count(i))
                ans.push_back(i);
        return ans;
    }
};
