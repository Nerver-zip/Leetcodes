using ll = long long;
class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        intervals = merge(intervals);

        int cost = brightness % 3 == 0 ? brightness/3 : brightness/3 + 1;
        
        ll ans = 0;

        for(const auto& interval : intervals){
            ans += 1LL * (interval[1] - interval[0] + 1) * cost;
        }

        return ans;
    }
private:
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