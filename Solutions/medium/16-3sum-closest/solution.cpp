class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int best = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size()-2; ++i) {
            int left = i + 1, right = nums.size()-1;
            while (left < right) {
                int choice = nums[i] + nums[left] + nums[right];

                if(abs(target - best) > abs(target - choice))
                    best = choice;

                if(choice > target)
                    --right;
                else if(choice < target)
                    ++left;
                else
                    return choice;
            }
        }

        return best;
    }
};