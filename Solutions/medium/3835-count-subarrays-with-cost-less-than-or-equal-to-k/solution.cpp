using ll = long long;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        const int size = nums.size();

        ll totalSubarrays = 1LL * size * (size+1)/2;
        set<pair<int,int>> mySet;
        ll count = 0;

        int minimum = INT_MAX, maximum = INT_MIN;
        for(int left = 0, right = 0; right < size; ++right){
            mySet.insert({nums[right], right});
            minimum = min(minimum, nums[right]);
            maximum = max(maximum, nums[right]);
            
            while((1LL * (maximum - minimum) * (right-left+1)) > k){
                int removed = nums[left];
                mySet.erase({removed, left});
                ++left;
                count += size - right;

                minimum = mySet.cbegin()->first;
                maximum = mySet.crbegin()->first;
            }
        }

        return totalSubarrays - count;
    }
};