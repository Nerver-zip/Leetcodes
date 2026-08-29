class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < nums.size()-1; i++)
        {
            int j = i+1;
            while (j < nums.size() && nums[i] > nums[j])
            {
                size--;
                j++;
            }
            i = j-1;
        }
        return size;        
    }
};