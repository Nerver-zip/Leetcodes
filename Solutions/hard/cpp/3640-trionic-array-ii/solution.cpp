using ll = long long;
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        ll ans = LLONG_MIN/4;
        ll a, b, c;

        a = b = c = ans;
        for (int i = 1; i < nums.size(); ++i) {
            ll new_a = LLONG_MIN/4, new_b = LLONG_MIN/4, new_c = LLONG_MIN/4;
            // max entre começar do estado anterior e expandir
            if(nums[i] > nums[i-1]){
                new_a = max(a + nums[i], 1LL * nums[i-1] + nums[i]);
                new_c = max(c + nums[i], b + nums[i]);
            }
            else if(nums[i] < nums[i-1]){
                new_b = max(b + nums[i], a + nums[i]);
            }
            ans = max(ans, new_c);
            a = new_a;
            b = new_b;
            c = new_c;
        }
        return ans;
    }
};