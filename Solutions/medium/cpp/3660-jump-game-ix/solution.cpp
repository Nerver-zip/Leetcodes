class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        const int n = nums.size();
        vector<array<int, 3>> stack;
        
        stack.push_back({0, 0, nums[0]});

        for(int i = 1; i < n; ++i){
            array<int, 3> curr = {i,i, nums[i]};

            auto& [left, right, val] = curr;

            while(!stack.empty() && stack.back()[2] > nums[i]){
                auto [stack_left, stack_right, stack_val] = stack.back();
                stack.pop_back();
                val = max(stack_val, val);
                left = stack_left;
            }

            stack.push_back(curr);
        }
        
        vector<int> ans;
        ans.reserve(n);

        for(int i = 0; i < stack.size(); ++i)
            for(int j = stack[i][0]; j <= stack[i][1]; ++j)
                ans.push_back(stack[i][2]);
        
        return ans;
    }
};