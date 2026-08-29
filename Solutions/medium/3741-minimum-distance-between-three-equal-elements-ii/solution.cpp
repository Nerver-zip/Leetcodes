class Solution {
public:
    // Slide i, j, k for each equal num
    int minimumDistance(vector<int>& nums) {
        const int n = nums.size();    
    
        unordered_map<int, vector<int>> map;
        int ans = numeric_limits<int>::max();

        for(int i = 0; i < n; ++i){
            auto& bucket = map[nums[i]];

            if(bucket.size() < 3){
                bucket.push_back(i);
            }
            else {
                bucket[0] = bucket[1];
                bucket[1] = bucket[2];
                bucket[2] = i;
            }

            if(bucket.size() == 3){
                ans = min(ans, abs(bucket[0] - bucket[1]) + abs(bucket[1] - bucket[2]) + abs(bucket[2] - bucket[0]));
            }
        }

        return ans == numeric_limits<int>::max() ? -1 : ans;
    }
};