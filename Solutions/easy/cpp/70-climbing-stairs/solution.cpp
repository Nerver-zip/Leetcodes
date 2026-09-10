class Solution {
private:
    vector<int> memo;
    
    int calculate(int n){
        if(n < 2)
            return 1;
        if(!memo[n])
            memo[n] = calculate(n-1) + calculate(n-2);
        return memo[n];
    }
public:
    int climbStairs(int n) {
        memo.assign(n + 1, 0);
        memo[n] = calculate(n);
        return memo[n];
    }
};