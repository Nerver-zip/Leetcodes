class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total_sum = accumulate(stones.begin(), stones.end(), 0);        

        // dp[i] = é possível atingir um subconjunto com soma == i
        vector<bool> dp(total_sum + 1, 0);
        
        // A ideia é tentar atingir um subconjunto com soma == total_sum / 2.
        // Nesse caso a resposta é otima -> 0, vamos pegar o mais proximo disso.

        dp[0] = true;
        for(int n : stones){
            for(int s = total_sum; s >= n; --s)
                dp[s] = dp[s] || dp[s - n];
        }
        
        int target = total_sum / 2;
        int res = numeric_limits<int>::max();

        while (target && !dp[target]) --target;
        
        return total_sum - 2 * target;
    }
};