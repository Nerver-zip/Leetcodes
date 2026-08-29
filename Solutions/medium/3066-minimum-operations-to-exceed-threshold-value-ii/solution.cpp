class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        std::priority_queue<long long,vector<long long>,std::greater<>> minHeap;
        for (const auto& number : nums)
            minHeap.push(number);
        
        int count = 0;
        while (minHeap.top() < k)
        {
            long long min = minHeap.top();
            minHeap.pop();
            long long max = minHeap.top();
            minHeap.pop();
            count++;
            minHeap.push(min * 2 + max);
        }
        return count;
    }
};