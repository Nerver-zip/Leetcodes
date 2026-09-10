using ll = long long;
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        ll sum = 0;
        
        int ans = INT_MAX;

        for (int right = 0, left = 0; right < nums.size(); ++right) {
            int curr = nums[right];
            
            if(freq[curr] == 0)
                sum += curr;
            
            ++freq[curr];
            
            while (sum >= k) {
                
                ans = min(ans, right - left + 1);

                --freq[nums[left]];

                if(freq[nums[left]] == 0)
                    sum -= nums[left];

                ++left;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};