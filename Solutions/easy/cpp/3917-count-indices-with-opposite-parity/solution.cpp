class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        const int n = nums.size();
        
        vector<int> ans(n, 0);

        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                if((nums[i] & 1) != (nums[j] & 1))
                    ++ans[i];
            }
        }

        return ans;
    }
};