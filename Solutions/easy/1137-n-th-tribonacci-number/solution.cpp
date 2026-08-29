class Solution {
private:
    int solve(int n, vector<int>& memo){
        if(n <= 0)
            return 0;
        if(n == 1 || n == 2)
            return 1;
        if(memo[n] == -1)
            memo[n] = solve(n-3, memo) + solve(n-2, memo) + solve(n-1, memo);
        return memo[n];
    }
public:
    int tribonacci(int n) {
        vector<int> memo(n+1, -1);
        return solve(n, memo);
    }
};