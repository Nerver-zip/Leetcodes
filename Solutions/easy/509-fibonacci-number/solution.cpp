class Solution {
public:
    int fib(int n) {
        if(n < 1)
            return 0;

        int n_2 = 0;
        int n_1 = 1;
        int ans = 1;
        
        for (int i = 2; i <= n; ++i) {
            ans = n_1 + n_2;
            n_2 = n_1;
            n_1 = ans;
        }

        return ans; 
    }
};