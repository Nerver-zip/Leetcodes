class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int longest = nums.size()-1;

        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] != nums[i-1] + 1){
                longest = i-1;
                break;
            }
        }

        int sum = 0;
        
        for(int i = 0; i <= longest; ++i){
            sum += nums[i];
        }
        
        unordered_set<int> set(nums.begin(), nums.end());
        
        while(set.contains(sum)){
            ++sum;
        }

        return sum;
    }
};