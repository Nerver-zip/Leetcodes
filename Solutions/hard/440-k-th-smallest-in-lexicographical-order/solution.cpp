class Solution {
private:
    // Conta quantos números existem entre prefixo "curr" e "curr + 1"
    long long countSteps(long long n, long long curr, long long next) {
        long long steps = 0;
        while (curr <= n) {
            steps += min(n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }

public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        --k;  // Já estamos no primeiro elemento

        while (k > 0) {
            long long steps = countSteps(n, curr, curr + 1);
            if (steps <= k) {
                // Podemos pular toda essa subárvore
                curr += 1;
                k -= steps;
            } else {
                // Entramos na subárvore do prefixo atual
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};