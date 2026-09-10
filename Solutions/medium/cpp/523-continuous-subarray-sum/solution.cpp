using ll = long long;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1; // prefix sum before array
        
        ll prefix = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            prefix += nums[i];
            
            int r;
            if (k == 0)
                r = prefix;
            else
                r = (int)((prefix % k + k) % k); 
            
            if (mp.count(r)) {
                if (i - mp[r] >= 2)
                    return true;
            } else {
                mp[r] = i;  // store only first occurrence
            }
        }
        
        return false;
    }
};