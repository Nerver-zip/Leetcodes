class Solution {
private:
    void permutate(int index, vector<int>& nums, vector<vector<int>>& ans){
        if (index == nums.size())
        {
            ans.push_back(nums);
        }
        for (int i = index; i < nums.size(); i++)
        {
            std::swap(nums[i],nums[index]);
            permutate(index+1,nums,ans);
            std::swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        permutate(0,nums,ans);

        return ans;
    }
};