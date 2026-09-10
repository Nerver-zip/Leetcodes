struct Compare{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.first == b.first)
            return a.second > b.second; //lowest index to untie
        return a.first < b.first; //priority for greater first
    }
};

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;

        for (int i = 0; i < nums.size(); ++i)
            pq.push({nums[i], i});

        vector<pair<int,int>> sortedNums; 
        while (!pq.empty() && k--)
        {
            sortedNums.push_back(pq.top());
            pq.pop();
        }
        
        sort(sortedNums.begin(), sortedNums.end(), [](const auto& a, const auto& b){
            return a.second < b.second;
        });
        
        vector<int> ans;
        for (const auto& [n, _] : sortedNums)
            ans.push_back(n);

        return ans;
    }
};