class Solution {
private:
    void subsetRecur(int i, const vector<int>& arr, vector<vector<int>>& subsets, vector<int>& subset) {
        if (i == arr.size()) {
            subsets.push_back(subset);
            return;
        }

        subset.push_back(arr[i]);
        subsetRecur(i+1, arr, subsets, subset); 
        subset.pop_back();
        subsetRecur(i+1, arr, subsets, subset);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;

        for (int n : nums) {
            target |= n;
        }

        vector<vector<int>> subsets;
        vector<int> subset;
        subsetRecur(0, nums, subsets, subset);
        
        int ans = 0;

        for (const auto& sub : subsets) {
            int res = 0;
            for (const auto& n : sub) {
                res |= n;
            }
            if(res == target)
                ++ans;
        } 
        return ans;
    }
};
