//Use binary search to get the lowerbound of possible answers
class Solution {
private:
    bool canFormPPairs(const vector<int>& nums, int p, int maxDiff){
        int count = 0;
        int i = 0;

        while (i < nums.size() - 1)
        {
            if (nums[i+1] - nums[i] <= maxDiff)
            {
                //found two new pairs
                count++; 
                i += 2; //take the two indexes
            }
            else
                ++i; //test next one
        }
        return count >= p;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int low = 0; //min possible diff
        int high = nums.back() - nums.front(); //max possible diff since array is sorted

        while (low < high)
        {
            int mid = low + (high-low)/2;
            if(canFormPPairs(nums, p, mid)){
                high = mid;
            }
            else
                low = mid + 1;
        }
        return low;
    }
};