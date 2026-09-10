class Solution {
private:
    vector<int> dfs(const vector<int>& nums, unordered_map<int, vector<int>>& cache, int index){
        if (cache.count(index))
            return cache[index];

        vector<int> maxSubset;
        for (int i = index+1; i < nums.size(); i++)
        {
            if (nums[i] % nums[index] == 0)
            {
                vector<int> subset = dfs(nums, cache, i);
                if (subset.size() > maxSubset.size()) {
                    maxSubset = subset;
                }
            }
        }
        vector<int> res = {nums[index]};
        res.insert(res.end(), maxSubset.begin(), maxSubset.end());
        cache[index] = res;
        return res;
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> cache;

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> temp = dfs(nums, cache, i);
            if (ans.size() < temp.size())
                ans = temp;
        }
        return ans;
    }
};