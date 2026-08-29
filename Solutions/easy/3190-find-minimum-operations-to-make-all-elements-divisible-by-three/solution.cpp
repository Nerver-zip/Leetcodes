class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;

        for (int n : nums){
            
            int countAdd = n % 3 == 0 ? 0 : 
                       (n+1) % 3 == 0 ? 1 : 
                       (n+2) % 3 == 0 ? 2 :
                       3;

            int countSub = n % 3 == 0 ? 0 : 
                           (n-1) % 3 == 0 ? 1 : 
                           (n-2) % 3 == 0 ? 2 :
                           3;

            ans += min(countAdd, countSub);
        }
        return ans; 
    }
};