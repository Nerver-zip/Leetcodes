#define MOD 1000000007

class Solution {
private:
    int modExpo(int base, int exp, int mod) {
        long long result = 1;
        long long b = base;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * b) % mod;
            b = (b * b) % mod;
            exp /= 2;
        }
        return result;
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size()-1;
        long long ans = 0;

        while (left <= right)
        {
            if (nums[left] + nums[right] <= target)
            {
                int exp = right - left;
                ans = (ans + modExpo(2, exp, MOD)) % MOD;
                left++;
            }
            else
                right--;
        }
        return static_cast<int>(ans);
    }
};