class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int,int> map;

        for(int n : nums){
            ++map[n];
        }
        
        vector<int> ans;
        ans.reserve(nums.size());

        while(true){
            vector<int> erase;
            
            for(auto& [n, freq] : map){
                ans.push_back(n);
                --freq;

                if(freq == 0){
                    erase.push_back(n);
                }
            }

            for(int n : erase){
                map.erase(n);
            }

            if(map.size() == 0){
                break;
            }
        }

        return ans;
    }
};