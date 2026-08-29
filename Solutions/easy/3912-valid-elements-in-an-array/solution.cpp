class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int> ans;
        
        auto isGreaterLeft = [&](int idx){
            for(int i = 0; i < idx; ++i){
                if(nums[idx] <= nums[i])
                    return false;
            }

            return true;
        };

        auto isGreaterRight = [&](int idx){
            for(int i = idx + 1; i < nums.size(); ++i){
                if(nums[idx] <= nums[i])
                    return false;
            }

            return true;
        };

        for(int i = 0; i < nums.size(); ++i){
            if(isGreaterLeft(i) || isGreaterRight(i))
                ans.push_back(nums[i]);
        }

        return ans;
    }
};