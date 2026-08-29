class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;

        // {firstValue, endIndex, length, lastValue, secondValue}
        vector<array<int, 5>> bottoms;

        int start = 0;
        for (int i = 1; i <= n; ++i) {
            // break when sequence decreases or we reach the end
            if (i == n || nums[i] < nums[i - 1]) {
                int first = nums[start];
                int end = i - 1;
                int len = i - start;
                int last = nums[i - 1];
                int second = (start + 1 < n ? nums[start + 1] : nums[start]);
                bottoms.push_back({first, end, len, last, second});
                start = i;
            }
        }

        if (bottoms.size() == 1)
            return n;

        int ans = 0, mergedAns = 0, finalAns = 0;
        auto [prevFirst, prevEnd, prevLen, prevLast, prevSecond] = bottoms[0];

        for (int i = 1; i < (int)bottoms.size(); ++i) {
            auto [currFirst, currEnd, currLen, currLast, currSecond] = bottoms[i];

            // both possible merges:
            bool canMerge = false;

            // replace the breaking element (first of next block)
            if (prevLast <= currSecond)
                canMerge = true;

            // replace the last element of the previous block
            if (prevLen > 1) {
                int prevPenultimate = nums[prevEnd - 1];
                if (prevPenultimate <= currFirst)
                    canMerge = true;
            }

            if (canMerge)
                mergedAns = max(mergedAns, prevLen + currLen);

            // Or extend one side with one replacement
            ans = max({ans, prevLen + 1, currLen + 1});
            finalAns = max({finalAns, ans, mergedAns});

            prevFirst = currFirst;
            prevEnd = currEnd;
            prevLen = currLen;
            prevLast = currLast;
            prevSecond = currSecond;
        }

        return min(finalAns, n);
    }
};