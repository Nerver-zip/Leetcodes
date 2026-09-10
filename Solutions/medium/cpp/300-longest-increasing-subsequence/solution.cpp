class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> subs = {nums[0]};
        
        for(int n : nums){
            if(subs.back() < n)
                subs.push_back(n);
            auto it = lower_bound(subs.begin(), subs.end(), n);
            *it = n;
        }

        return subs.size();
    }
};