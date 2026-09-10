class Solution {
public:
    // We want to find x such that x | (x+1) = y
    // The difference between x and y is always going to be a power of 2
    // We can test all powers instead of all numbers
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        ans.reserve(nums.size());
        
        for(int y : nums){
            int x = INT32_MAX; 
            
            for (int diff = 1; diff < INT32_MAX; diff = diff << 1) {
                int curr_x = y - diff; // y - x = diff -> x = y - diff; 
                if(curr_x < 1)
                    break;
                
                if((curr_x | (curr_x + 1)) == y)
                    x = min(x, curr_x);
            }
            
            ans.push_back(x == INT32_MAX ? -1 : x);
        }

        return ans;
    }
};