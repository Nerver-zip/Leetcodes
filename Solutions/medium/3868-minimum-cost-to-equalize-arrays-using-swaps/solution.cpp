class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size();
        unordered_map<int, int> diff;

        for(int x : nums1)
            ++diff[x];
        for(int x : nums2)
            --diff[x];
        
        int ans = 0;
        for(const auto& [x, f] : diff){
            if(f & 1)
                return -1;
            
            // Checks a single side since we are swapping
            if(f > 0)
                ans += f/2;
        }

        return ans;
    }
};