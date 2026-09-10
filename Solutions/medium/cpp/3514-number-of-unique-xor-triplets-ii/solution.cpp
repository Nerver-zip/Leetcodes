class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int n = nums.size();
        unordered_set<int> set;

        for(int i = 0; i < n; ++i){
            for(int j = i; j < n; ++j){
                set.insert(nums[i] ^ nums[j]);
            }
        }
        
        unordered_set<int> ans;
        for(int a : nums){
            for(int b : set){
                ans.insert(a ^ b);
            }
        }

        return ans.size();
    }
};