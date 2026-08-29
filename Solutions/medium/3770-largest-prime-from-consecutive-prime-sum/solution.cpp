class Solution {
using ll = long long;
public:
    int largestPrime(int n) {
        sieveOfEratosthenes(n);

        int ans = 0;

        for (int i = prefix.size()-1; i >= 0; --i) {
            if(prefix[i] < prime.size() && prime[prefix[i]])
                return prefix[i];
        }

        return 0;
    }

private:
    vector<ll> prefix;
    vector<bool> prime;
    void sieveOfEratosthenes(int n) {
        prime.assign(n + 1, true);

        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        
        ll curr = 0;
        for (int p = 2; p <= n; p++)
            if (prime[p]){
                prefix.push_back(curr + p * 1LL);
                curr = prefix.back();
            }
    }
};