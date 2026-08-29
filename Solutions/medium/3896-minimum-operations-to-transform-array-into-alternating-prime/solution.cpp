using ll = long long;
class Solution {
public:
    Solution(){
        sieveOfEratosthenes(1e5 + 3);
    }
    
    int minOperations(vector<int>& nums) {
        const int n = nums.size();
        int ans = 0;
        
        for(int i = 0; i < n; ++i){
            if(i % 2 == 0){
                // find closest prime
                if(!isPrime[nums[i]]){
                    int p = *upper_bound(primes.begin(), primes.end(), nums[i]);
                    ans += abs(nums[i] - p);
                }
            }
            else {
                int x = nums[i];
                while(isPrime[x]){
                    ++ans;
                    ++x;
                }
            }
        }

        return ans;
    }

private:
    vector<ll> primes;
    vector<bool> isPrime;
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