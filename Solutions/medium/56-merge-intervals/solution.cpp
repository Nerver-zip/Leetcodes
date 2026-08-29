class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[](const auto& a, const auto& b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        vector<int> curr = intervals[0];
        vector<vector<int>> ans;
        
        for (int i = 1; i < intervals.size(); ++i){
            int start = intervals[i][0], end = intervals[i][1];

            if(curr[1] >= start){
                if(end > curr[1])
                    curr[1] = end;
            }
            else{
                ans.push_back(curr);
                curr[0] = start;
                curr[1] = end;
            }
        }
        
        if(ans.size() == 0 || ans.back()[0] != curr[0] && ans.back()[1] != curr[1])
            ans.push_back(curr);

        return ans;
    }
};