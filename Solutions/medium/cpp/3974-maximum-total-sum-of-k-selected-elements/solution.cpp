using ll = long long;

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        priority_queue<int> pq(nums.begin(), nums.end());
        
        ll ans = 0;
        while(k--){
            ll top = pq.top();
            pq.pop();

            if(mul){
                ans += top * mul;
                --mul;
            }
            else
                ans += top;
        }

        return ans;
    }
};