class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // separate numbers in groups of queues
        vector<int> sortedNums = nums;
        ranges::sort(sortedNums);

        vector<deque<int>> queueList;

        // val -> group
        unordered_map<int,int> map;

        for (const auto& num : sortedNums)
        {
            if (queueList.empty() || num - queueList.back().back() > limit)
            {
                queueList.push_back({});
            }
            queueList.back().push_back(num);
            map[num] = queueList.size()-1;
        }
        vector<int> ans;
        for (const auto& num : nums)
        {
            int i = map[num];
            ans.push_back(queueList[i].front());
            queueList[i].pop_front();
        }
        return ans;
    }
};