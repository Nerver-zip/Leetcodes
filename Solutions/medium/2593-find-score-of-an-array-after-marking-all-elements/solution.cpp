class Solution {
public:
    long long findScore(vector<int>& nums) {
        std::unordered_set<int> mySet;
        std::priority_queue<std::pair<int,int>,vector<std::pair<int, int>>,std::greater<>> myQueue;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            myQueue.push({nums[i],i});
        }
    
    while (mySet.size() < nums.size()) 
    {
        if (!myQueue.empty() && mySet.find(myQueue.top().second) == mySet.end()) 
        {
            sum += myQueue.top().first;
            mySet.insert(myQueue.top().second);
            if(myQueue.top().second == 0)
                mySet.insert(myQueue.top().second + 1);
            else if (myQueue.top().second == nums.size()-1)
                mySet.insert(myQueue.top().second - 1);
            else
            {
                mySet.insert(myQueue.top().second + 1);
                mySet.insert(myQueue.top().second - 1);
            }
        }
        myQueue.pop();
    }
    return sum;   
    }
};
