class Solution {
public:
    int makeTheIntegerZero(long long num1, long long num2) {
       
        for (long long k = 1; k <= 60; ++k) {
            long long v = num1 - k * num2;
            
            // Se v negativo, não é possível
            if (v < 0) break;

            // Conta número de bits 1 em v
            int cnt = __builtin_popcountll(v);
            
            // Se o número de bits 1 <= k <= v, é possível
            if (cnt <= k && k <= v) {
                return k;
            }
        }
        return -1; 
    }
};