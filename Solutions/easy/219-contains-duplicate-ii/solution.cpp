class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for (int left = 0, right = 0; right < nums.size(); ++right) {
            ++freq[nums[right]];
        
            if(right - left > k){
                int& f = freq[nums[left]];
                --f;

                if(f == 0)
                    freq.erase(nums[left]);
                ++left;
            }

            if(freq.at(nums[right]) > 1)
                return true;
        }
        return false;
    }
};