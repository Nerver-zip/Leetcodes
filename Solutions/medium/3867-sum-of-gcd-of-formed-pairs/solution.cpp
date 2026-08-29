using ll = long long;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        const int size = nums.size();
        vector<int> prefixGcd;
        prefixGcd.reserve(size);
        
        int maximum = nums.front();
        for(int n : nums){
            maximum = max(maximum, n);
            prefixGcd.push_back(gcd(n, maximum));
        }
        
        ranges::sort(prefixGcd);

        ll ans = 0;
        
        int left = 0, right = size-1;
        
        while(left < right){
            ans += 1LL * gcd(prefixGcd[left], prefixGcd[right]);
            ++left;
            --right;
        }

        return ans;
    }
};