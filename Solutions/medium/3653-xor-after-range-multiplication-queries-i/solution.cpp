class Solution {
public:
    static constexpr int MOD = 1000000007; 
    
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int idx;
        for(const auto& query : queries){
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];

            idx = l;

            while(idx <= r){
                nums[idx] = (1LL * nums[idx] * v) % MOD;
                idx += k;
            }
        }

        int ans = 0;

        for(int n : nums)
            ans ^= n;

        return ans;
    }
};