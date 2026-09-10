class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> closest(n);
        closest[0] = 1;
        closest[n-1] = n-2;

        for (int i = 1; i < n-1; i++) {
            int left = nums[i] - nums[i-1];
            int right = nums[i+1] - nums[i];
            if (left <= right) closest[i] = i-1;
            else closest[i] = i+1;
        }

        // cost going right
        vector<int> costR(n-1);
        for (int i = 0; i < n-1; i++) {
            if (closest[i] == i+1)
                costR[i] = 1;
            else
                costR[i] = nums[i+1] - nums[i];
        }

        vector<int> prefR(n, 0);
        for (int i = 1; i < n; i++) {
            prefR[i] = prefR[i-1] + costR[i-1];
        }

        // cost going left
        vector<int> costL(n-1);
        for (int i = 1; i < n; i++) {
            if (closest[i] == i-1)
                costL[i-1] = 1;
            else
                costL[i-1] = nums[i] - nums[i-1];
        }

        vector<int> prefL(n, 0);
        for (int i = 1; i < n; i++) {
            prefL[i] = prefL[i-1] + costL[i-1];
        }

        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            if (l < r)
                ans.push_back(prefR[r] - prefR[l]);
            else
                ans.push_back(prefL[l] - prefL[r]);
        }

        return ans;
    }
};