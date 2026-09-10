class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        const int MOD = 1e9 + 7;
        int n = nums1.size();

        vector<pair<int,int>> segments;
        vector<pair<int,int>> pureOnes;

        for(int i = 0; i < n; ++i){
            if(nums0[i] == 0){
                pureOnes.push_back({nums1[i], nums0[i]});
            } else {
                segments.push_back({nums1[i], nums0[i]});
            }
        }

        sort(segments.begin(), segments.end(), [](auto &a, auto &b){
            if(a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        });

        vector<pair<int,int>> order;
        for(auto &p : pureOnes) order.push_back(p);
        for(auto &p : segments) order.push_back(p);

        long long ans = 0;

        for(auto &[ones, zeroes] : order){
            for(int i = 0; i < ones; ++i)
                ans = (ans * 2 + 1) % MOD;

            for(int i = 0; i < zeroes; ++i)
                ans = (ans * 2) % MOD;
        }

        return ans;
    }
};