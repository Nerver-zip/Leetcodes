class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        const int n = nums.size();
        unordered_map<int, vector<int>> map;

        for(int i = 0; i < n; ++i)
            map[nums[i]].push_back(i);

        int ans = numeric_limits<int>::max();
        for(int i = 0; i < n; ++i){
            auto it = map.find(getReversed(nums[i]));
            
            if(it == map.end())
                continue;

            auto& list = it->second;
            auto it2 = upper_bound(list.begin(), list.end(), i);
            if(it2 != list.end())
                ans = min(ans, *it2 - i);
            }

        return ans == numeric_limits<int>::max() ? -1 : ans;
    }
private:
    int getReversed(int n){
        string num = to_string(n);
        reverse(num.begin(), num.end());
        return stoi(num);
    }
};