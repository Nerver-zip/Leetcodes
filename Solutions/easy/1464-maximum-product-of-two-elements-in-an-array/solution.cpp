class Solution {
public:
    int maxProduct(vector<int>& nums) {
        ranges::sort(nums, greater{});

        return (nums[0]-1) * (nums[1]-1);
    }
};