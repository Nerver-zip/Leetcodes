class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> seen;

        for(int n : nums)
            seen.insert(n);
        
        auto it = seen.rbegin();
        int ans = *it;
        ++it;
        
        for (; it != seen.rend(); ++it) {
            if(*it <= 0)
                break;
            ans += *it;
        }
        return ans;
    }
};