class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums,int lower,int upper) {
        ranges::sort(nums);

        vector<vector<int>> ans;
        int next = lower;

        for (int n : nums) {
            if (n < next) {
                continue; // duplicata ou valor já coberto
            }

            if (n > upper) {
                break;
            }

            if (n > next) {
                ans.push_back({next, n - 1});
            }

            next = n + 1;
        }

        if (next <= upper) {
            ans.push_back({next, upper});
        }

        return ans;
    }
};