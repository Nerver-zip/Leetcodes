using ll = long long;
class Solution {
public:
    Solution(){
        if(primes.size() == 0 || isPrime.size() == 0)
            sieveOfEratosthenes(1000);
    }

    int sumOfPrimesInRange(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        
        int r = stoi(s);
        int ans = 0;
        for(int i = min(n, r); i <= max(n,r); ++i){
            if(isPrime[i])
                ans += i;
        }

        return ans;
    }

private:
    static inline vector<ll> primes;
    static inline vector<bool> isPrime;
    
    void sieveOfEratosthenes(int n) {

        isPrime.assign(n + 1, true);
        isPrime[0] = false, isPrime[1] = false;

        for (int p = 2; p * p <= n; p++) {
            if (isPrime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    isPrime[i] = false;
            }
        }
        
        ll curr = 0;
        for (int p = 2; p <= n; p++)
            if (isPrime[p])
                primes.push_back(p);
    }
};