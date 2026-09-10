class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ans = 0;

        for (int n : nums) {
            if(n % 2 == 0)
                ans |= n;
        }
        return ans;
    }
};