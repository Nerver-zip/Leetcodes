class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); 
        int ans = 0;
        for (int n : nums) {
            auto it = upper_bound(nums.begin(), nums.end(), n);
            auto res = nums.end() - it;
            if(res >= k)
                ++ans;
        }

        return ans;
    }
};