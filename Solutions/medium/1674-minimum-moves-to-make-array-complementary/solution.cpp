class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        const int n = nums.size();

        vector<int> diff(2 * limit + 2);
        
        int i = 0, j = n-1;
        while(i < j){
            int a = nums[i], b = nums[j];

            int sum = a + b;
            
            int L = min(a,b) + 1;
            int R = max(a,b) + limit;
            
            // Modifica 2
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;
            
            // Modifica 1
            diff[L] -= 1;
            diff[R+1] += 1;


            // Modifica nenhum
            diff[sum] -= 1;
            diff[sum+1] += 1;
            ++i;
            --j;
        }

        int ans = INT_MAX;
        int curr = 0;

        for(int s = 2; s <= 2*limit; s++){
            curr += diff[s];
            ans = min(ans, curr);
        }

        return ans;
    }
};
