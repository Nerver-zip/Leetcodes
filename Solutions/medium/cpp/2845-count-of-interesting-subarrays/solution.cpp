class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        vector<int> prefix(nums.size()+1, 0);

        for (int i = 1; i <= nums.size(); i++)
            prefix[i] = prefix[i-1] + (nums[i-1] % modulo == k ? 1 : 0);

        long long ans = 0;
        unordered_map<int,long long> freq;
        freq[0] = 1;

        for (int i = 1; i <= nums.size(); i++)
        {
            int need = (prefix[i] + modulo - k) % modulo;
            ans += freq[need];
            freq[prefix[i] % modulo]++;
        }
        return ans;
    }
};