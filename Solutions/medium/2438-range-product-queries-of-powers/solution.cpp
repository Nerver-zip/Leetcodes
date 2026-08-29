class Solution {
public:
    vector<int> getPowers(int n) {
        if (n == 0)
            return {0};
        
        vector<int> bin;
        while (n > 0) {
            bin.push_back(n % 2);
            n /= 2;
        }
        //with the binary number reversed, make powers array
        vector<int> powers;
        int p = 0;
        for (int n : bin) {
            if(n != 0)
                powers.push_back(pow(2, p));
            ++p;
        }
        return powers;
}
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers = getPowers(n);
        const int MOD = 1e9 + 7;

        vector<int> ans;
        for (const auto& query : queries){
            long long curr = 1;
            for (int i = query[0]; i <= query[1]; ++i)        
                curr = (curr * powers[i]) % MOD;
            ans.push_back(curr);
        }
        return ans;
    }
};
