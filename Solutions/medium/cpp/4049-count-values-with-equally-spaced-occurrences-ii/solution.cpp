class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> map;
        unordered_set<int> banned;

        for(int i = 0; i < nums.size(); ++i){
            if(banned.count(nums[i])){
                continue;
            }

            auto& v = map[nums[i]];
            
            if(v.size() < 2){
                v.push_back(i);
            }
            else{
                if(abs(v.back() - i) != abs(v[v.size()-2] - v.back())){
                    v.clear();
                    v.shrink_to_fit();
                    banned.insert(nums[i]);
                }
                else{
                    v.push_back(i);
                }
            }
        }
        
        auto check = [](const vector<int>& arr){
            return arr.size() > 2;
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