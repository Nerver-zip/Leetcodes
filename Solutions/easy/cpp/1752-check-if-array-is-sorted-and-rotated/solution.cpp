class Solution {
public:
    bool check(vector<int>& nums) {
        const int n = nums.size();
        int i = 0;
        bool broke = false;
        for(i = 1; i < n; ++i){
            if(nums[i-1] > nums[i]){
                broke = true;
                break;
            }
        }
        

        for(i = i+1; i < n; ++i)
            if(nums[i-1] > nums[i])
                return false;
        
        return broke && nums.back() > nums.front() ? false : true;
    }
};