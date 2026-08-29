// If we see consecutive 1's and k > 0 return false
// If we see a 1 followed by a zero, if the number of zeros in between prev 1 and the next one is < 1, return false
// Otherwise, return true
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            if(nums[i] == 1 && nums[i+1] == 1 && k > 0)
                return false;
            if(nums[i] == 1 && nums[i+1] == 0){
                int count = 0;
                ++i;
                while(i < nums.size() && nums[i] == 0){
                    ++i;
                    ++count;
                    if(i < nums.size() && nums[i] && count < k)
                        return false;
                }
                --i;
            }
        }

        return true;
    }
};