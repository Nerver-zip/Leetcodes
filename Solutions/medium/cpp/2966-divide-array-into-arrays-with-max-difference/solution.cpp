class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int size = nums.size()/3;

        vector<vector<int>> ans;

        for (int i = 1; i < nums.size()-1 && ans.size() < size; ++i)
            if (nums[i] - nums[i-1] <= k && nums[i+1] - nums[i] <= k && nums[i+1] - nums[i-1] <= k){
                ans.push_back({nums[i-1], nums[i], nums[i+1]});
                i += 2;
            }
        
        return ans.size() == size ? ans : vector<vector<int>>();
    }
};