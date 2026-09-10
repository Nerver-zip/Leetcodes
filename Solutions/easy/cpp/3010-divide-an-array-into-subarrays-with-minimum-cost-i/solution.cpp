// Get the first and then the two smallest elements for the minimum cost
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n0 = nums[0];
        sort(nums.begin(), nums.end());
        
        int n1 = n0 == nums[0] ? nums[1] : nums[0];
        int n2 = (n0 == nums[0] && n1 == nums[1])
              || (n0 == nums[1] && n1 == nums[0]) ? nums[2] : nums[1];

        return n0 + n1 + n2; 
    }
};