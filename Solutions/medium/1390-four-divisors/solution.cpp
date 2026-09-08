using ll = long long;
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        const int MAX = 100000;
        vector<int> primes = sieveOfEratosthenes(MAX);
        vector<int> sum(MAX + 1, 0);

        // Two cases p³ and p * q
        
        // p³
        for (int p : primes) {
            ll n = 1LL * p * p * p;
            if(n > MAX)
                break;

            sum[n] = 1 + p + p * p + p * p * p; 
        }

        // p * q
        for (int i = 0; i < primes.size(); ++i) {
            for (int j = i+1; j < primes.size(); ++j) {
                ll n = 1LL * primes[i] * primes[j];
                if(n > MAX)
                    break;

                sum[n] = 1 + primes[i] + primes[j] + primes[i] * primes[j];
            }
        }

        int ans = 0;

        for (int n : nums) {
            ans += sum[n];
        }
        
        return ans;
    }

private:
    vector<bool> isPrime;
    vector<int> sieveOfEratosthenes(int n) {

        isPrime.assign(n + 1, true);
        isPrime[0] = false, isPrime[1] = false;
        

        vector<int> primes;
        for (int p = 2; p * p <= n; p++) {
            if (isPrime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    isPrime[i] = false;
            }
        }

        for (int p = 2; p <= n; p++)
            if (isPrime[p]){
                primes.push_back(p);
            }

        return primes;
    }
};