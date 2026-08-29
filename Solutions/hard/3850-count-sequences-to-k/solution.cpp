using ll = long long;
using i128 = __int128_t;
class Solution {
public:
    int countSequences(vector<int>& nums, ll k) {
        this->nums = nums;
        this->k = k;
        memo.clear();
        return dfs(0, 1, 1);
    }

private:
    vector<int> nums;
    ll k;

    map<tuple<int,i128,i128>, int> memo;

    int dfs(int i, i128 num, i128 den) {

        auto g = gcd128(num, den);
        num /= g;
        den /= g;

        if(i == nums.size())
            return num == (i128)k * den;

        auto key = make_tuple(i,num,den);
        if(memo.count(key)) return memo[key];

        int ans = 0;

        ans += dfs(i+1, num*nums[i], den);
        ans += dfs(i+1, num, den*nums[i]);
        ans += dfs(i+1, num, den);

        return memo[key] = ans;
    }
    
    i128 gcd128(i128 a, i128 b) {
        while (b) {
            i128 t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
};