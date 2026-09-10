class Solution {
public:
    int minCost(int n) {
        if(n == 1)
            return 0;
        if(n == 2)
            return 1;
        if(n == 3)
            return 3;
        
        int ans = 3;
        int curr = 3;
        for(int i = 3; i < n; ++i){
            ans += curr;
            curr++;
        }

        return ans;
    }
};