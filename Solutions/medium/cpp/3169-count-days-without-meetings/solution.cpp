class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        std::priority_queue<pair<int,int>, vector<pair<int,int>>, std::greater<>> minHeap;
        for (const auto& meeting : meetings)
            minHeap.push({meeting[0], meeting[1]});
        
        int totalBusyDays = 0;
        auto [left, right] = minHeap.top();

        //Merges intervals together storing size in totalBusyDays
        while (!minHeap.empty())
        {
            auto [currLeft, currRight] = minHeap.top();
            minHeap.pop();
            if (currLeft > right) 
            {
                totalBusyDays += right - left + 1;
                left = currLeft;
            }
            right = currRight > right ? currRight : right;
            if (minHeap.empty())
            {
                totalBusyDays += right - left + 1;
            }
        }
        return days - totalBusyDays;    
    }
};