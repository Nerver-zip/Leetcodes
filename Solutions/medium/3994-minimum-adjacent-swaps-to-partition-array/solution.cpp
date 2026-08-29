constexpr int MOD = 1000000007; 

class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        const int n = nums.size();
        int ans = 0;
        
        int pivot = 0;

        vector<int> temp;

        // partition 1
        for(int i = 0; i < n; ++i){
            if(nums[i] < a){
                ans = (ans + (i - pivot)) % MOD;
                ++pivot;
            }
            else{
                temp.push_back(nums[i]);
            }
        }

        // part 2
        pivot = 0;
        for(int i = 0; i < temp.size(); ++i){
            if(temp[i] >= a && temp[i] <= b){
                ans = (ans + (i - pivot)) % MOD;
                ++pivot;
            }
        }

        // part 3 comes out naturally

        return ans;
    }
};