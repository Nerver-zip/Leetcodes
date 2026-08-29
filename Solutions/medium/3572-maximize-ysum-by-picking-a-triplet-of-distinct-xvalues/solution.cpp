class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        priority_queue<pair<int, int>, vector<pair<int,int>>> maxHeap;

        for (int i = 0; i < y.size(); ++i)
            maxHeap.push({y[i], i});
        
        int sum = 0;
        unordered_set<int> distinct;

        while (!maxHeap.empty())
        {
            auto [curr, index] = maxHeap.top();
            maxHeap.pop();

            if (distinct.find(x[index]) == distinct.end())
            {
                sum += curr;
                distinct.insert(x[index]);
            }
            
            if (distinct.size() == 3)
                return sum;        
        }        
        return -1;
    }
};