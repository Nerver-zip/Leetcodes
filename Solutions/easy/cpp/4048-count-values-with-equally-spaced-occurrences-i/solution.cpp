class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> map;

        for(int i = 0; i < nums.size(); ++i){
            map[nums[i]].push_back(i);
        }
        
        auto check = [](const vector<int>& arr){
            if(arr.size() != 3){
                return false;
            }

            return abs(arr[0] - arr[1]) == abs(arr[1] - arr[2]);
        };
        
        int ans = 0;
        for(const auto& [n, v] : map){
            if(check(v)){
                ++ans;
            }
        }

        return ans;
    }
};