class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[](const auto& a, const auto& b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        int ans = 0;
        for(int i = 0; i < intervals.size(); i++){
            int start1 = intervals[i][0], end1 = intervals[i][1];

            for(int j = i; j < intervals.size(); ++j){
                if(i == j){
                    continue;
                }
                
                int start2 = intervals[j][0], end2 = intervals[j][1];
                
                if(start2 <= end1){
                    ++ans;
                }
            }
        }
        
        return ans;
    }
};