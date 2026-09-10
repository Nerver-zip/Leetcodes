using ll = long long;
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int ans = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            ll sum = 0;
            unordered_set<int> set;
            for (int j = i; j < nums.size(); ++j) {
                set.insert(nums[j]);
                sum += nums[j];
                if(set.count(sum))
                    ++ans;
            }
        }

        return ans;
    }
};