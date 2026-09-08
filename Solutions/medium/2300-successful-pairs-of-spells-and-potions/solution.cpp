class Solution {
private:
    int lowerbound(const vector<int>& nums, long long target, const long long f){
        int left = 0, right = nums.size()-1, i = -1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (target <= static_cast<long long>(nums[mid]) * f){
                i = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return i;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        const int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans;

        for (long long spell : spells) {
            int left = lowerbound(potions, success, spell);
            if(left == -1)
                ans.push_back(0);
            else
                ans.push_back(m - left);
        }

        return ans;
    }
};