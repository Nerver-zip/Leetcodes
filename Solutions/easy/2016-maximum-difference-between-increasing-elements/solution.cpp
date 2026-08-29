class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        map<int, int> freqMap;

        for (int i = 1; i < nums.size(); ++i)
            freqMap[nums[i]]++;

        int ans = INT32_MIN;

        for (int i = 1; i < nums.size(); ++i)
        {
            ans = max(ans, freqMap.rbegin()->first - nums[i-1]);
            freqMap[nums[i]]--;
            if (freqMap[nums[i]] == 0)
                freqMap.erase(nums[i]);
        }
        
        return ans <= 0 ? -1 : ans;
    }
};