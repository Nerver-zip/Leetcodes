class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        const int n = nums.size();

        unordered_map<int, vector<int>> map;

        for(int i = 0; i < n; ++i)
            map[nums[i]].push_back(i);
        

        vector<int> ans;
        ans.reserve(queries.size());

        for(int i : queries){
            auto& list = map[nums[i]];

            if(list.size() == 1){
                ans.push_back(-1);
                continue;
            }
            
            auto it = lower_bound(list.begin(), list.end(), i);
            int idx = it - list.begin();

            // Calc min distance in circular array
            // the formula is min(abs(i - j), n - abs(i-j))
            // so we try for each neighbor
            
            int res = numeric_limits<int>::max();
            const int m = list.size();

            // right neigh
            int j = list[(idx + 1) % m];
            res = min(res, min(abs(i - j), n - abs(i - j)));

            // left neigh
            int k = list[(idx - 1 + m) % m];
            res = min(res, min(abs(i - k), n - abs(i - k)));

            ans.push_back(res);
        }

        return ans;
    }
};