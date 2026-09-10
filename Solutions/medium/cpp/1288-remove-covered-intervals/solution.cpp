class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        int removed = 0;

        for(int i = 0; i < n; ++i){
            int a = intervals[i][0], b = intervals[i][1];
            for(int j = 0; j < n; ++j){
                if(i == j) continue;

                int c = intervals[j][0], d = intervals[j][1];

                if(a >= c && b <= d){
                    ++removed;
                    break;
                }
            }
        }

        return n - removed;
    }
};