using ll = long long;
class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        const int n = nums.size();
        
        int ans = 0;

        for(int i = 0; i < n; ++i){
            ll sum = 0;
            for(int j = i; j < n; ++j){
                sum += nums[j];
                if(sum % 10 != x)
                    continue;
                auto [first, last] = getFirstLast(sum);
                if(first == x && last == x)
                    ++ans;
            }
        }
        return ans;
    }
private:
    pair<int,int> getFirstLast(ll x){
        int last = x % 10;
        
        int first;
        while(x){
            first = x % 10;
            x /= 10;
        }

        return {first, last};
    }
};