#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        vector<long long> prefixSum(nums.size(), 0);
        vector<long long> suffixSum(nums.size(), 0);

        priority_queue<int> maxHeap;
        long long currSum = 0;

        for (int i = 0; i < n; i++) {
            currSum += nums[i];
            maxHeap.push(nums[i]);
        }
        prefixSum[n - 1] = currSum;

        for (int i = n; i < 2 * n; i++) {
            maxHeap.push(nums[i]);
            currSum += nums[i];

            int top = maxHeap.top();
            maxHeap.pop();
            currSum -= top;

            prefixSum[i] = currSum;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        currSum = 0;

        for (int i = 3 * n - 1; i >= 2 * n; i--) {
            currSum += nums[i];
            minHeap.push(nums[i]);
        }
        suffixSum[2 * n] = currSum;

        for (int i = 2 * n - 1; i >= n; i--) {
            minHeap.push(nums[i]);
            currSum += nums[i];

            int top = minHeap.top();
            minHeap.pop();
            currSum -= top;

            suffixSum[i] = currSum;
        }

        long long answer = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; i++) {
            answer = min(answer, prefixSum[i] - suffixSum[i + 1]);
        }

        return answer;
    }
};
