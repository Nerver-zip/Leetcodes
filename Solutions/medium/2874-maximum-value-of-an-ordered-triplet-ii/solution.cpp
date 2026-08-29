class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefix(size,0);
        vector<int> sufix(size,0);

        prefix[0] = nums[0];
        for (int i = 1; i < size; i++)
            prefix[i] = std::max(prefix[i-1],nums[i]);
        
        sufix[size-1] = nums[size-1];
        for (int i = size-2; i >= 0; i--)
            sufix[i] = std::max(sufix[i+1], nums[i]);
        
        long long ans = 0;
        for (int i = 1; i < size-1; i++)
            ans = std::max(ans, static_cast<long long>((prefix[i-1] - nums[i])) * sufix[i+1]);
        
        return ans; 
    }
};