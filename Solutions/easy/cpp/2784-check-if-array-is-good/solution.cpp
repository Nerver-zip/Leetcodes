class Solution {
public:
    bool isGood(vector<int>& nums) {
        const int n = nums.size()-1;
        sort(nums.begin(), nums.end());
        
        for(int x = 1; x <= n; ++x){
            if(nums[x-1] != x)
                return false;
        }

        if(nums.back() != n)
            return false;

        return true;
    }
};