class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        //separate numbers in groups of queues
        vector<int> sortedNums = nums;
        std::sort(sortedNums.begin(),sortedNums.end());

        vector<std::deque<int>> queueList;
        std::unordered_map<int,int> myMap;

        for (const auto& num : sortedNums)
        {
            if (queueList.empty() || abs(num - queueList.back().back()) > limit)
            {
                queueList.push_back({});
            }
            queueList.back().push_back(num);
            myMap[num] = queueList.size()-1;
        }
        vector<int> ans;
        for (const auto& num : nums)
        {
            int i = myMap[num];
            ans.push_back(queueList[i].front());
            queueList[i].pop_front();
        }
        return ans;
    }
};