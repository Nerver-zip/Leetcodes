class Solution {
public:
    //ans[i] = -1 it rained in the i day
    //ans[i] = lake dryed in the ith day if rains[i] == 0
    //Either that or any valid lake
    vector<int> avoidFlood(vector<int>& rains) {
        const int n = rains.size();
        unordered_map<int, int> lastRain;
        set<int> dryDays;
        vector<int> ans(n, 1);

        for(int i = 0; i < n; ++i){
            if(rains[i] > 0){
                int lake = rains[i];
                ans[i] = -1;

                if(lastRain.count(lake)){
                    int prevDay = lastRain[lake];
                    auto it = dryDays.upper_bound(prevDay);
                    if(it == dryDays.end())
                        return {};
                    ans[*it] = lake;
                    dryDays.erase(it);
                }
                lastRain[lake] = i;
            }
            else
                dryDays.insert(i);
        }
        return ans;
    }
};