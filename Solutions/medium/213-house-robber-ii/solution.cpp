class Solution {
private:
    int dfs(const vector<int>& nums, vector<int>& cache, int index, int size){
        if (index >= size)
            return 0;
        if(cache[index] > -1){
            return cache[index];
        }   
        cache[index] = std::max(
            dfs(nums, cache, index+1, size),
            nums[index] + dfs(nums, cache, index+2, size)
        );
        return cache[index];
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        vector<int> cache(nums.size(), -1);
        vector<int> cache2(nums.size(), -1);
        int size = nums.size();
        return std::max(dfs(nums, cache, 0, size-1), dfs(nums, cache2, 1, size));
    }
};