class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        vector<int> freq(101, 0);

        for (int n : nums) {
            ++freq[n];
        }
        
        int ans = 0;
        for (int i = 0; i < freq.size(); ++i)
            if(freq[i] % k == 0)
                ans += freq[i] * i;

        return ans;
    }
};