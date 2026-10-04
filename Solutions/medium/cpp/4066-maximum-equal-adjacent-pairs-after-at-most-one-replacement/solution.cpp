using ll = long long;

class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        
        unordered_map<ll, int> map;       
        
        int curr_equal = 0;
        
        auto pack = [](int a, int b)->ll{
            return 1LL * a << 32 | b;
        };

        for(int i = 0; i < nums.size()-1; ++i){
            int a = max(nums[i], nums[i+1]);
            int b = min(nums[i], nums[i+1]);

            if(a == b){
                ++curr_equal;
            }
            else{
                ++map[pack(a,b)];
            }
        }
        
        int ans = curr_equal;

        for(const auto& [_, freq] : map){
            ans = max(ans, curr_equal + freq);
        }

        return ans;
    }
};