class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        std::unordered_set<int> mySet;

        for (const auto& n : nums)
        {
            if(n < k)
                return -1;
            mySet.insert(n);
        }
        return mySet.count(k) ? mySet.size()-1 : mySet.size();
    }
};
