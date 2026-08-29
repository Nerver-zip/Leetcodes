class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        const int n = nums.size();

        int ans = 0;
        for(int i = 0; i < n; ++i){
            int freq = 0;
            for(int j = i; j < n; ++j){
                int size = j - i + 1;
                if(nums[j] == target)
                    ++freq;

                int req = size/2 + 1;

                if(freq >= req){
                    ++ans;
                }
            }
        }

        return ans;
    }
};