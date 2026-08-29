class UnionFind {
public:
    UnionFind(int size){
        parent.resize(size);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(size, 0);
    }
    
    int find(int x){
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    
    bool unite(int x, int y){
        int pX = find(x), pY = find(y);
        
        if(pX == pY)
            return false;
        
        if(rank[pX] > rank[pY])
            parent[pY] = pX;
        else if(rank[pX] < rank[pY])
            parent[pX] = pY;
        else {
            parent[pX] = pY;
            ++rank[pY];
        }
        return true;
    }
private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    // Static pre computed sieve
    Solution() {
        vector<bool> isPrime;
        isPrime.assign(N + 1, true);
        isPrime[0] = false, isPrime[1] = false;

        for (int p = 2; p * p <= N; p++) {
            if (isPrime[p] == true) {
                for (int i = p * p; i <= N; i += p)
                    isPrime[i] = false;
            }
        }
        
        int curr = 0;
        for (int p = 2; p <= N; p++)
            if (isPrime[p]){
                primes.push_back(p);
            }
    }

    int largestComponentSize(vector<int>& nums) {
        int maxPrime = 0;
        unordered_map<int, vector<int>> primeFactors;
        
        // get all prime factors for each number
        for(int n : nums){
            auto& list = primeFactors[n];
            int num = n;

            for (int i = 0; i < primes.size() && 1LL * primes[i] * primes[i] <= num; ++i) {
                if (num % primes[i] == 0) {
                    list.push_back(primes[i]);
                    maxPrime = max(maxPrime, primes[i]);
                    while (num % primes[i] == 0)
                        num /= primes[i];
                }
            }
            
            // n itself is prime
            if (list.empty()) {
                maxPrime = max(maxPrime, n);
            } else if (num > 1) {
                // large prime factor
                list.push_back(num);
                maxPrime = max(maxPrime, num);
            }
        }
        
        // Link prime factors
        UnionFind uf(maxPrime+1);
        for(const auto& [_, list] : primeFactors){
            for (int i = 1; i < list.size(); ++i) {
                uf.unite(list[i-1], list[i]);
            }
        }

        unordered_map<int, int> groupFreq;
        int ans = 0;
        for(const auto& [n, list] : primeFactors){
            int id = list.empty() ? uf.find(n) : uf.find(list[0]);
            int& f = groupFreq[id];
            ans = max(ans, ++f);
        }

        return ans;
    }
private:
    static constexpr int N = 1e5;
    static inline vector<int> primes;
};