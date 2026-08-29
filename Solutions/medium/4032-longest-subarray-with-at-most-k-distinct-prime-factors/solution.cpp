using ll  = long long;
template <int N>
struct Sieve {
    array<bool, N+1> isPrime{};
    array<int, N/2> primes;
    constexpr Sieve() : isPrime{}, primes{} {
        for(int i = 0; i <= N; ++i){
            isPrime[i] = true;
        }

        isPrime[0] = false, isPrime[1] = false;
        
        for (int p = 2; p * p <= N; p++) {
            if (isPrime[p] == true) {
                for (int i = p * p; i <= N; i += p)
                    isPrime[i] = false;
            }
        }
        

        ll curr = 0;
        int i = 0;
        for (int p = 2; p <= N; p++)
            if (isPrime[p])
                primes[i++] = p;
    }
};

Sieve<10001> sieve;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> primeFactors;
        const auto& primes = sieve.primes;
        
        // get all prime factors for each number
        for (int n : nums) {
              auto [it, inserted] = primeFactors.try_emplace(n);
              if (!inserted) {
                  continue;
              }
              auto& list = it->second;
              int num = n;
              for (int i = 0;
                   i < static_cast<int>(primes.size()) &&
                   1LL * primes[i] * primes[i] <= num;
                   ++i) {

                  if (num % primes[i] == 0) {
                      list.push_back(primes[i]);

                      while (num % primes[i] == 0) {
                          num /= primes[i];
                      }
                  }
              }
              if (num > 1) {
                  list.push_back(num);
              }
        }

        unordered_map<int, int> primeFactorsFreq;
        int ans = 0;
        
        auto incrementFreq = [&](int x){
            auto& list = primeFactors[x];
            
            for(int n : list){
                ++primeFactorsFreq[n];
            }
        };

        auto decrementFreq = [&](int x){
            auto& list = primeFactors[x];
            
            for(int n : list){
                --primeFactorsFreq[n];
                if(primeFactorsFreq[n] == 0){
                    primeFactorsFreq.erase(n);
                }
            }
        };

        for(int left = 0, right = 0; right < nums.size(); ++right){
            incrementFreq(nums[right]);

            while(primeFactorsFreq.size() > k){
                decrementFreq(nums[left]);
                ++left;
            }

            ans = max(right - left + 1, ans);
        }
        
        return ans;
    }
};