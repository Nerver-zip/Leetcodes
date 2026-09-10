class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long count = 0;
        std::priority_queue<int, vector<int>, std::function<bool(int, int)>> minHeap(
            [&nums](int a, int b) { return nums[a] > nums[b]; });
        std::priority_queue<int, vector<int>, std::function<bool(int, int)>> maxHeap(
            [&nums](int a, int b) { return nums[a] < nums[b]; });

        int right;
        int left = right = 0;
        
        while (right < nums.size())
        {
            minHeap.push(right);
            maxHeap.push(right);
            while (left < right && nums[maxHeap.top()] - nums[minHeap.top()] > 2)
            {
                left++;
                while (!maxHeap.empty() && maxHeap.top() < left)
                {
                    maxHeap.pop();
                }

                while (!minHeap.empty() && minHeap.top() < left)
                {
                    minHeap.pop();
                }
            }
            count += right - left + 1;
            right++; 
        }
        return count;
    }
};