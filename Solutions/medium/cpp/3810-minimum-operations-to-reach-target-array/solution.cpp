class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_set<int> seen;
        
        int operations = 0;

        for (int i = 0; i < target.size(); ++i) {
            if(nums[i] != target[i] && !seen.count(nums[i])){
                ++operations;
                seen.insert(nums[i]);
            }
        }

        return operations;
    }
};