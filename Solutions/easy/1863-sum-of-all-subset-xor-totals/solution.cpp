class Solution {
private:
    vector<vector<int>> subsets;
    void backtrack(const vector<int>& nums, vector<int>& curr, int index){
        if(index == nums.size()){
            subsets.push_back(curr);
            return;
        }

        curr.push_back(nums[index]);
        backtrack(nums, curr, index+1);

        curr.pop_back();
        backtrack(nums, curr, index+1);
        return;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> curr;
        backtrack(nums, curr, 0);

        int ans = 0;

        for (const auto& subset : subsets)
        {
            int mask = 0;
            for (const auto& n : subset)
            {
                mask ^= n;
            }
            ans += mask;
        }
        return ans;
    }
};