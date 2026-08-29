class Solution {
public:
    bool isIncRotation(vector<int>& nums) {
        int n = nums.size();
        int breaks = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] > nums[(i + 1) % n])
                breaks++;
        }

        return breaks <= 1;
    }

    bool isDecRotation(vector<int>& nums) {
        int n = nums.size();
        int breaks = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] < nums[(i + 1) % n])
                breaks++;
        }

        return breaks <= 1;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int pos0 = find(nums.begin(), nums.end(), 0) - nums.begin();

        int ans = INT_MAX;

        // increasing rotation
        if (isIncRotation(nums)) {
            int cost1 = pos0;

            int cost2 = 1 + min(
                pos0 + 1,
                n + 1 - pos0
            );

            ans = min(ans, min(cost1, cost2));
        }

        // decreasing rotation
        if (isDecRotation(nums)) {
            int cost1 = n - pos0;
            int cost2 = pos0 + 2;

            ans = min(ans, min(cost1, cost2));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};