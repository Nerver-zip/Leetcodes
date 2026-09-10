class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> map;
        unordered_set<int> unique(nums.begin(), nums.end());

        for (int n : nums)
            ++map[n];
        
        int operations = 0;
        for (int i = 0; i < nums.size() && nums.size() - i != unique.size(); ++i) {
            int j = i;
            ++operations;
            for (; j < nums.size() && j < i + 3; ++j) {
                --map[nums[j]];
                if(map[nums[j]] == 0)
                    unique.erase(nums[j]);
            }
            i = j-1;
        }
        return operations;
    }
};