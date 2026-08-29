class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        const int N = nums.size();
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            unordered_set<int> even, odd;
            for(int j = i; j < N; ++j){
                int n = nums[j];
                if(n % 2 == 0)
                    even.insert(n);
                else
                    odd.insert(n);

                if(even.size() == odd.size())
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};