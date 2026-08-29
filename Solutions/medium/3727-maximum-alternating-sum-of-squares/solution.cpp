class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        priority_queue<long long> maxHeap;
        priority_queue<long long, vector<long long>, greater<>> minHeap;

        for (int n : nums) {
            int x = n * n;
            maxHeap.push(x);
            minHeap.push(x);
        }

        long long ans = 0, operations = 0;
        
        while (operations < nums.size()) {
            ans += maxHeap.top();
            maxHeap.pop();
            ++operations;
            
            if(operations == nums.size())
                return ans;
            
            ans -= minHeap.top();
            minHeap.pop();
            ++operations;
        }
        return ans;
    }
};