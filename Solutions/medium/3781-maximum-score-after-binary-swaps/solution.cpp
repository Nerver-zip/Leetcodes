using ll = long long;
class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        priority_queue<ll> maxHeap;
        
        ll ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            maxHeap.push(nums[i]);

            if(s[i] == '1'){
                ans += maxHeap.top();
                maxHeap.pop();
            }
        }

        return ans;
    }
};