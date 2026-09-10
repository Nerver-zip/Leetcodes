class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        
        for (int p : primes) {
            while (n % p == 0)
                n /= p;
        }

        return n == 1;
    }
private:
    static inline vector<int> primes = {2,3,5};
};