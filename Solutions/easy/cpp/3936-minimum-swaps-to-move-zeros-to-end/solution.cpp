class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        const int n = nums.size();
        int zeroCount = 0;

        for(int n : nums)
            if(n == 0)
                ++zeroCount;
        
        int swaps = 0;
        for(int i = n-1; i >= 0 && zeroCount; --i){
            if(nums[i] != 0)
                ++swaps;
            --zeroCount;
        }

        return swaps;
    }
};