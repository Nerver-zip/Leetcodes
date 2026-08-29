class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = 0;
        for(int b = 0; b <= 30; ++b){
            vector<int> subs;
            for(int n : nums){
                if((1 << b) & n){
                    auto it = lower_bound(subs.begin(), subs.end(), n);
                    if(it == subs.end())
                        subs.push_back(n);
                    else
                        *it = n;
                }
            }
            ans = max(ans, (int)subs.size());
        }

        return ans;
    }
};