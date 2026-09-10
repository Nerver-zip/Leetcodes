class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        
        for (int i = 0; i < nums.size()-1; i++)
        {
            if (nums[i] == nums[i+1])
            {
                nums[i] = nums[i] * 2;
                nums[i+1] = 0;
            }
        }
        int left = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i]){
                std::swap(nums[i],nums[left]);
                left++;
            }
        }
        return nums;
    }
};