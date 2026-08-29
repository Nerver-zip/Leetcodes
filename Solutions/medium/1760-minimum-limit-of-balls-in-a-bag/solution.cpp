class Solution {
private:
    bool isPossible(int maxBalls, vector<int>& nums,int maxOperations){
        int total = 0;
        int operations;
        for (int i = 0; i < nums.size(); i++)
        {
            operations = ceil(nums[i] /(double)maxBalls) - 1;
            total += operations;
            if (total > maxOperations) return false;
        }
        return true;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = 0;
        for (auto num : nums) {
            right = max(right, num);
        }
        while (left < right)
        {
            int middle = (left + right) / 2;
            if(isPossible(middle,nums,maxOperations))
                right = middle;
            else
                left = middle + 1;
        }
        return left;
    }
};