class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> frequencyMap;
        unordered_set<int> uniqueSet;
        
        for (const auto& n : nums)
            uniqueSet.insert(n);
    
        int distinctTotal = uniqueSet.size();
        uniqueSet.clear();
        int left = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            uniqueSet.insert(nums[right]);
            frequencyMap[nums[right]]++;
            while (uniqueSet.size() == distinctTotal)
            {
                ans += nums.size() - right;
                frequencyMap[nums[left]]--;
                if (frequencyMap[nums[left]] == 0)
                    uniqueSet.erase(nums[left]);
                left++;
            }
        }
        return ans;
    }
};