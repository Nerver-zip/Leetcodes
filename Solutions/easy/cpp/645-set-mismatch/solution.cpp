class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        array<int, 10001> freq{};
        
        int max_n = 0;
        for (int n : nums){
            max_n = max(max_n, n);
            ++freq[n];
        }
        
        vector<int> ans(2,-1);
        
        for (int n = 1; n <= max_n; ++n) {
            if(freq[n] == 2)
                ans[0] = n;
            else if(freq[n] == 0)
                ans[1] = n;
        }

        if(ans[1] == -1)
            ans[1] = max_n + 1;

        return ans;
    }
};