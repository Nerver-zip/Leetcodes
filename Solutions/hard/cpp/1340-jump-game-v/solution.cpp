class Solution {
public:
    int dfs(int i) {
        if (memo[i] != -1) 
            return memo[i];

        int best = 1;

        // direita
        for (int x = 1; x <= d && i + x < n; x++) {
            if (arr[i] <= arr[i + x])
                break;
            best = std::max(best, 1 + dfs(i + x));
        }

        // esquerda
        for (int x = 1; x <= d && i - x >= 0; x++) {
            if (arr[i] <= arr[i - x])
                break;
            best = std::max(best, 1 + dfs(i - x));
        }

        return memo[i] = best;
    }

    int maxJumps(std::vector<int>& a, int d) {
        arr = a;
        this->d = d;
        n = arr.size();
        memo.assign(n, -1);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = std::max(ans, dfs(i));
        }
        return ans;
    }
private:
    int n;
    vector<int> memo;
    vector<int> arr;
    int d;
};