class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> freq;
        for (int p : power) 
            freq[p] += p;

        for (auto& [v, w] : freq)
            vals.push_back(v);

        sort(vals.begin(), vals.end());

        weights.resize(vals.size());
        
        for (int i = 0; i < vals.size(); ++i)
            weights[i] = freq[vals[i]];

        memo.assign(vals.size(), -1);
        return dfs(0);
    }
private:
    vector<int> vals;
    vector<long long> weights;
    vector<long long> memo;

    long long dfs(int i) {
        if (i >= vals.size()) 
            return 0;
        if (memo[i] != -1) 
            return memo[i];

        //skip
        long long skip = dfs(i + 1);

        //take
        int nextVal = vals[i] + 3;
        int j = lower_bound(vals.begin(), vals.end(), nextVal) - vals.begin();
        long long take = weights[i] + dfs(j);
        
        return memo[i] = max(skip, take);
    }
};