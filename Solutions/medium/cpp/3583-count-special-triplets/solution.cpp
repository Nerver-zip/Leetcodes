class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MODULO = 1e9 + 7;
        unordered_map<int, int> frequencyNext;
        unordered_map<int, int> frequencyPrev;

        for(int n : nums)
            frequencyNext[n]++;

        long long ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            frequencyNext[nums[i]]--;
            int pivot = nums[i] * 2;
            ans = (ans + 1LL * frequencyPrev[pivot] * frequencyNext[pivot]) % MODULO;
            frequencyPrev[nums[i]]++;
        }
        return ans;
    }
};