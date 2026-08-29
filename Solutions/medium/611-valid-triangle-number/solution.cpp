//Two Pointers + Binary Search = O(n² * log(n))
//Enough for N <= 1000
//From a fellow leetcoder:
//"Valid Triangle means if you added length of any 2 side it will be greater than 3rd side length"

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        const int n = nums.size();

        sort(nums.begin(), nums.end());
        
        int ans = 0;

        for (int i = 0; i < n-1; ++i)
            for (int j = i+1; j < n; ++j){
                int minToNotFormTriangle = nums[i] + nums[j];
                auto it = lower_bound(nums.begin() + j+1, nums.end(), minToNotFormTriangle);
                int index = it - nums.begin();
                ans += index - j - 1;
            } 

        return ans;
    }
};
