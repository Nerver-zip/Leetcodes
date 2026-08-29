class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            long long SIZE = nums.size();
            long long totalPairs = SIZE * (SIZE-1)/2;
            long long ans = 0;

            std::unordered_map<int,long long> frequencyMap;

            for (int i = 0; i < SIZE; i++)
            {
                frequencyMap[nums[i] - i]++;
            }
            
            for (const auto& frequency : frequencyMap)
            {
                if (frequency.second > 1)
                {
                    ans += frequency.second * (frequency.second-1)/2;
                }
            }
            return totalPairs - ans;
        }   
};