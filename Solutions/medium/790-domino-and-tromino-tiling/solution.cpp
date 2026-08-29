#define MODULO 1000000007
class Solution {
public:
    int numTilings(int n) {
        
        //A[N] = A[N-1] * 2 + A[N-3]
        
        long long n_3 = 1;
        long long n_2 = 2;
        long long n_1 = 5;
        
        if(n == 1)
            return n_3;
        if(n == 2)
            return n_2;
        if (n == 3)
            return n_1;
        
        long long ans;
        long long count = 0;
        for (int i = 4; i <= n; i++)
        {
            ans = (n_1 * 2 + n_3) % MODULO;
            n_3 = n_2;
            n_2 = n_1;
            n_1 = ans;
        }
        return ans;
    }
};