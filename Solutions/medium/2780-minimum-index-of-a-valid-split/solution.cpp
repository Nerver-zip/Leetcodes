class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        std::unordered_map<int,int> right;
        std::unordered_map<int,int> left;

        for (const auto& n : nums)
            right[n]++;
        
        for (int i = 0; i < nums.size(); i++)
        {
            right[nums[i]]--;
            left[nums[i]]++;

            int leftSize = i + 1;
            int rightSize = nums.size() - i - 1;

            if (2 * left[nums[i]] > leftSize && 2 * right[nums[i]] > rightSize)
                return i;        
        }
        return -1;
    }
};