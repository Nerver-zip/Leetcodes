class Solution {
private:
    const double TGT = 24.0;
    const double TOL = 1e-6;

    bool dfs(vector<double>& nums) {
        if (nums.size() == 1) {
            return abs(nums[0] - TGT) < TOL;
        }

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) 
                    continue;

                vector<double> next;
                for (int k = 0; k < nums.size(); ++k)
                    if (k != i && k != j) next.push_back(nums[k]);

                // Apply possible OPs
                double a = nums[i], b = nums[j];
                vector<double> ops = {a + b, a - b, b - a, a * b};
                
                if (b != 0) 
                    ops.push_back(a / b);
                if (a != 0) 
                    ops.push_back(b / a);

                for (double val : ops) {
                    next.push_back(val);
                    if (dfs(next)) 
                        return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return dfs(nums);
    }
};
