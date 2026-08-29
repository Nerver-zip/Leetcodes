class Solution {
public:
    Solution(){
        if(spf.empty())
            spf_init(1e6);
    }

    int minJumps(vector<int>& nums) {
        const int n = nums.size();
        unordered_map<int, vector<int>> bucketMap;
        
        for(int i = 0; i < n; ++i){
            auto primes = getPrimeFactors(nums[i]);
            for(int p : primes)
                bucketMap[p].push_back(i);
        }

        // [steps, i]
        queue<pair<int,int>> q;
        vector<bool> visited(n, false);
        q.push({0, 0});
        visited[0] = true;

        while(!q.empty()){
            auto [steps, currIdx] = q.front();
            
            if(currIdx == n-1)
                return steps;

            q.pop();
            
            if(currIdx+1 < n && !visited[currIdx+1]){
                q.push({steps + 1, currIdx+1});
                visited[currIdx+1] = true;
            }
            if(currIdx-1 > 0 && !visited[currIdx-1]){
                q.push({steps + 1, currIdx-1});
                visited[currIdx-1] = true;
            }
            
            auto& bucket = bucketMap[nums[currIdx]];
            for(int idx : bucket){
                if(!visited[idx]){
                    q.push({steps + 1, idx});
                    visited[idx] = true;
                }
            }
            bucket.clear();
        }

        return n-1;
    }

private:
    static inline vector<int> spf;
    void spf_init(int n){
        spf.resize(n+1);
        iota(spf.begin(), spf.end(), 0);

        for (int i = 2; i * i <= n; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= n; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }
    }

    vector<int> getPrimeFactors(int x) {
        vector<int> primes;

        while (x > 1) {
            int p = spf[x];
            primes.push_back(p);

            while (x % p == 0)
                x /= p;
        }

        return primes;
    }
};