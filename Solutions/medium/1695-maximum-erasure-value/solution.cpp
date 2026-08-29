class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        const int size = nums.size();
        unordered_map<int, int> freqMap;
        int left = 0, right = 0;
        long long curr = 0, ans = 0;

        for (;right < size; ++right) {
            ++freqMap[nums[right]];
            while (freqMap[nums[right]] > 1){
                --freqMap[nums[left]];
                curr -= nums[left];
                ++left;
            }
            curr += nums[right];
            ans = max(ans, curr);
        }
        return ans;
    }
};