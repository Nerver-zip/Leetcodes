class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        const int n = nums.size();

        int maxVal = numeric_limits<int>::min();
        
        vector<int> minValues(n, numeric_limits<int>::max());
        
        minValues[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; --i){
            minValues[i] = min(minValues[i+1], nums[i]);
        }

        

        for(int i = 0; i < n; ++i){
            maxVal = max(maxVal, nums[i]);
            int minVal = minValues[i];
            
            int instability = maxVal - minVal;

            if(instability <= k)
                return i;
        }
        
        return -1;
    }
};