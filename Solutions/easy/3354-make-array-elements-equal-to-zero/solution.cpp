#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")

static int x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        const int N = nums.size();
        
        auto simulate = [](vector<int> arr, int curr, bool right){
            while (curr >= 0 && curr < arr.size()) {   
                if(arr[curr] == 0 && right)
                    ++curr;
                else if (arr[curr] == 0 && !right)
                    --curr;
                else if(arr[curr] > 0){
                    --arr[curr];
                    
                    if(right){
                        right = false;
                        --curr;
                    }
                    else{
                        right = true;
                        ++curr;
                    }
                }
            }

            for(int n : arr)
                if(n != 0)
                    return false;
            return true;
        };

        int ans = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0){
                
                if(simulate(nums, i, true))
                    ++ans;
                if(simulate(nums, i, false))
                    ++ans;
            }
        }
        
        return ans;
    }
};