using ll = long long;
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        const int n = nums.size();
        deque<ll> dq(nums.begin(), nums.end()); 
        
        ll first_half = 0, last_half = 0;

        for(int i = 0; i < n/2; ++i){
            first_half += 1LL * nums[i];
        }
        
        
        for(int i = n/2; i < n; ++i){
            last_half += 1LL * nums[i];
        }

        
        int ans = 0;
        for(int r = 0; r < nums.size(); ++r){
            if(first_half > last_half){
                ++ans;
            }

            first_half += dq[n/2];
            last_half -= dq[n/2];
            last_half += dq.front();
            first_half -= dq.front();
            dq.push_back(dq.front());
            dq.pop_front();
        }

        return ans;

    }
};