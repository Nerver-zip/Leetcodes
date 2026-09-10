class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        const int n = nums.size();
        unordered_map<int, int> freq;    
        
        int ans = 0;

        for(int left = 0, right = 0; right < n; ++right){
            int& f = freq[nums[right]];
            ++f;
            
            while(f > k){
                --freq[nums[left]];
                ++left;
            }

            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};