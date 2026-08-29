class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        std::priority_queue<std::pair<int,int>,vector<std::pair<int,int>>,std::greater<>> minHeap;

        for (int i = 0; i < nums.size(); i++)
        {
            minHeap.push({nums[i],i});
        }

        while (k--)
        {
            std::pair<int,int> top = minHeap.top();
            nums[top.second] *= multiplier;
            minHeap.pop();
            minHeap.push({nums[top.second],top.second});
        }
        return nums;
    }
};