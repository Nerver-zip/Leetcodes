class Solution {
public:
    long long splitArray(vector<int>& nums) {
        const int n = nums.size();
        vector<bool> inc(n);
        vector<bool> dec(n);

        inc[0] = true;
        for(int i = 1; i < n; ++i)
            inc[i] = inc[i-1] && nums[i] > nums[i-1];
        
        dec[n-1] = true;
        for(int i = n-2; i >= 0; --i)
            dec[i] = dec[i+1] && nums[i] > nums[i+1];
        
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];

        for (int i = 1; i < n; ++i)
            prefix[i] = prefix[i-1] + nums[i];
        
        long long total = prefix[n-1];
        
        //Check splits
        long long ans = LLONG_MAX;

        for (int i = 0; i < n-1; ++i)
            if(inc[i] && dec[i+1])
                ans = min(ans, abs(prefix[i] - (total - prefix[i])));

        return ans == LLONG_MAX ? -1 : ans;
    }
};