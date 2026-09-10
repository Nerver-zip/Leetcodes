class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        int m = n - 1;

        vector<long long> D(m);
        for (int i = 0; i < m; i++) {
            D[i] = (long long)nums[i + 1] - nums[i];
        }

        vector<int> leftRun(m);
        leftRun[0] = 1;

        for (int i = 1; i < m; i++) {
            if (D[i] == D[i - 1])
                leftRun[i] = leftRun[i - 1] + 1;
            else
                leftRun[i] = 1;
        }

        vector<int> rightRun(m);
        rightRun[m - 1] = 1;

        for (int i = m - 2; i >= 0; i--) {
            if (D[i] == D[i + 1])
                rightRun[i] = rightRun[i + 1] + 1;
            else
                rightRun[i] = 1;
        }

        int maxLen = 0;

        for (int i = 0; i < m; i++)
            maxLen = max(maxLen, leftRun[i]);

        if (maxLen < m)
            maxLen++;

        for (int i = 1; i < m; i++) {
            long long sum = D[i - 1] + D[i];

            if (sum % 2 == 0) {
                long long c = sum / 2;
                int currentLen = 2;

                if (i >= 2 && D[i - 2] == c)
                    currentLen += leftRun[i - 2];

                if (i + 1 < m && D[i + 1] == c)
                    currentLen += rightRun[i + 1];

                maxLen = max(maxLen, currentLen);
            }
        }

        return maxLen + 1;
    }
};