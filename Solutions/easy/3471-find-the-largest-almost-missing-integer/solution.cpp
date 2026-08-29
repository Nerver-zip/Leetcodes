class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
    
        const int n = nums.size();
        
        deque<int> dq;
        map<int,int, greater<int>> map;

        for(int n : nums){
            dq.push_back(n);
            
            if(dq.size() > k){
                dq.pop_front();
            }

            // numbers inside a single window can appear multiple times
            // they only count once into the freq map
            if(dq.size() == k){
                unordered_set<int> set;
                for(const auto& x : dq){
                    if(!set.count(x)){
                        ++map[x];
                    }
                    set.insert(x);
                }
            }
        }
         
        for(const auto& [k, f] : map){
            if(f == 1){
                return k;
            }
        }

        return -1;
    }
};