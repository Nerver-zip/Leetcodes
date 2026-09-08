class Solution {
private:
    bool canZeroArray(vector<int>& nums, vector<vector<int>>& queries, int k){
        int n = nums.size();
        vector<int> diffArray(n + 1, 0);

        for (int i = 0; i < k; i++)
        {
            int left = queries[i][0];
            int right = queries[i][1];
            int max = queries[i][2];

            diffArray[left] -= max;
            diffArray[right + 1] += max;
        }
        
        //Apply changes
        int currentDecrement = 0;
        for (int i = 0; i < nums.size(); i++) {
            currentDecrement += diffArray[i];  
            nums[i] += currentDecrement;
            if (nums[i] > 0) return false;  
        }       
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0;
        int right = queries.size();
        int ans = -1;

        while (left <= right)
        {
            int mid = left + (right-left)/2;
            vector<int> temp = nums;
            if (canZeroArray(temp, queries, mid))
            {
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return ans;
    }
};