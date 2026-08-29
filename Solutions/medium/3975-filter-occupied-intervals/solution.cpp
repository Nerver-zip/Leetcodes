class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
               
        auto merge = [](vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end(),[](const auto& a, const auto& b){
                return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
            });

            vector<vector<int>> ans;
            
            ans.push_back(intervals[0]);
            for (int i = 1; i < intervals.size(); ++i){
                if(intervals[i][0]-1 <= ans.back()[1]){
                    ans.back()[1] = max(ans.back()[1], intervals[i][1]);
                }
                else
                    ans.push_back(intervals[i]);
            }
            
            return ans;
        };
        
        occupiedIntervals = merge(occupiedIntervals);

        vector<vector<int>> ans;
        
        for(auto& interval : occupiedIntervals){
            int start = interval[0], end = interval[1];
            
            if(end < freeStart || start > freeEnd){
                ans.emplace_back(interval);
                continue;
            }
            // middle of interval, this creates a brandnew interval
            if(start < freeStart){
                ans.push_back({start, freeStart -1});
            }
            if(end > freeEnd){
                ans.push_back({freeEnd+1, end});
            }
            // else skip completely
            //else if(start >= freeStart && end <= freeEnd)
            //    continue;
        }

        if(!ans.empty())
            ans = merge(ans);
        
        return ans;
    }
};