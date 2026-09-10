class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        int remainder = total % p;

        if(remainder == 0)
            return 0;

        unordered_map<int, int> remainderToIndex;
        remainderToIndex[0] = -1;

        int currSum = 0;
        int ans = nums.size();
        
        for (int i = 0; i < nums.size(); ++i) {
            currSum = (currSum + nums[i]) % p;
            int target = (currSum - remainder + p) % p;
            auto it = remainderToIndex.find(target);

            if(it != remainderToIndex.end()){
                ans = min(ans, i - it->second);
            }

            remainderToIndex[currSum] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};