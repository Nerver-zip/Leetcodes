class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        vector<pair<int,int>> startTimes; // {pos, time}

        for (int i = 0; i < intervals.size(); ++i) {
            
            startTimes.push_back({i, intervals[i][0]});
        }

        sort(startTimes.begin(), startTimes.end(), [](const auto& a, const auto& b){return a.second < b.second;});
        
        vector<int> ans;
        for (int i = 0; i < intervals.size(); ++i) {
            int end = intervals[i][1];

            auto it = lower_bound(startTimes.begin(), startTimes.end(), end, [](const pair<int,int>& a, int val){return a.second < val;});

            if(it != startTimes.end())
                ans.push_back(it->first);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};