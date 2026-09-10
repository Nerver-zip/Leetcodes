class Solution {
public:
    int maxValidSplits(vector<int>& nums){ 
        const int n = nums.size();
        int ans = 0;
        
        auto count = [&](int idx){
            int prefix = 0;
            int res = 0;

            vector<int> suffix(n+1, 0);
            
            for(int i = n-1; i >= 0; --i){
                if(idx == i){
                    suffix[i] = suffix[i+1];
                    continue;
                }
                suffix[i] = gcd(suffix[i+1], nums[i]);
            }

            for(int i = 0; i < n; ++i){
                if(idx == i){
                    continue;
                }
                prefix = gcd(prefix, nums[i]);
                if(prefix == suffix[i+1]){
                    ++res;
                }
            }

            return res;
        };
        
        ans = count(-1);
        
        for(int i = 0; i < nums.size(); ++i){
            ans = max(ans, count(i));
        }

        return ans;
    }
};