#define BOUND 1000000007 
class Solution {
private:
int modExpo(long long base, long long exp, int mod) {
    long long result = 1;
    long long b = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * b) % mod;
        b = (b * b) % mod;
        exp /= 2;
    }
    return result;
}

//if N is odd: ans = 5^(n/2+1) * 4^(n/2)
//if N is even: ans = 5^(n/2) * 4^(n/2)
public:
    int countGoodNumbers(long long n) {
        long long pow5 = modExpo(5, (n + 1) / 2, BOUND);
        long long pow4 = modExpo(4, n / 2, BOUND);
        return pow5 * pow4 % BOUND;
    }
};