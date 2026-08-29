class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });
        
        int nonOverlapping = 0, lastEnding = INT32_MIN;

        for (const auto& interval : intervals) {
            if(interval[0] >= lastEnding){
                lastEnding = interval[1];
                ++nonOverlapping;
            }
        }

        return intervals.size() - nonOverlapping;
    }
};