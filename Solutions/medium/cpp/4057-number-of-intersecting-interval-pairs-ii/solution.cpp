using ll = long long;

class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[](const auto& a, const auto& b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        ll ans = 0;

        for(int i = 0; i < intervals.size(); ++i){

            int j = upper_bound(intervals.begin()+i+1, intervals.end(), intervals[i][1], [](int val, const vector<int>& a){
                return val < a[0];   
            }) - intervals.begin();
        
            ans += j - i - 1;  
        }
        
        return ans;
    }
};