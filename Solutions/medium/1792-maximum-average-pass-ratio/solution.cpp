class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        double ans = 0.0;
        priority_queue<pair<double,int>,vector<pair<double,int>>> maxHeap;

        for (int i = 0; i < classes.size(); i++)
        {
            ans += static_cast<double>(classes[i][0]) / classes[i][1];
            maxHeap.push({static_cast<double>((classes[i][0]) + 1)  / (classes[i][1] + 1) -  
                         static_cast<double>(classes[i][0])  / classes[i][1],  i});
        }

        while (!maxHeap.empty() && extraStudents--)
        {
            auto [ratio, index] = maxHeap.top();
            ans += ratio;
            maxHeap.pop();
            maxHeap.push({static_cast<double>((++classes[index][0]) + 1)  / (++classes[index][1] + 1) -  
                         static_cast<double>(classes[index][0])  / classes[index][1],  index});
        }
        
        return ans/classes.size();
    }
};