class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        const int n = events.size();
        map<int, int> eventMap; //Max val seen starting at time t {time_t, val}

        int maxSeen = INT32_MIN;

        sort(events.begin(), events.end(), [](const auto& a, const auto& b){
            return a[0] < b[0];
        });

        for (int i = n-1; i >= 0; --i) {
            int start = events[i][0], val = events[i][2];
            maxSeen = max(maxSeen, val);
            eventMap[start] = maxSeen;
        }
        
        int ans = 0;
        for (const auto& event : events) {
            int start = event[0], end = event[1], curr = event[2];
            
            auto it = eventMap.upper_bound(end); // Pega o max visto apos o end
            if(it != eventMap.end())
                curr += it->second;

            ans = max(ans, curr);
        }
        return ans;
    }
};