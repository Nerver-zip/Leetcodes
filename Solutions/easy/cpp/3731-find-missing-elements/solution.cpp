class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        ranges::sort(nums);

        vector<int> ans;
        
        int prev = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            int curr = nums[i];
            while(curr > prev + 1){
                ans.push_back(prev + 1);
                ++prev;
            }
            prev = curr;
        }

        return ans;
    }
};