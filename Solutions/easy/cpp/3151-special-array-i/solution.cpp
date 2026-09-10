class Solution {
private:
    bool isDifferentParityNeighbor(vector<int>& nums, int index){
        bool isOdd = nums[index] % 2 == 0 ? false : true;

        if (isOdd)
            return (index-1 < 0 || nums[index-1] % 2 == 0) && (index+1 >= nums.size() || nums[index+1] % 2 == 0); 
        return (index-1 < 0 || nums[index-1] % 2 != 0) && (index+1 >= nums.size() || nums[index+1] % 2 != 0);
    }
public:
    bool isArraySpecial(vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); i+=2)
        {
            if(!isDifferentParityNeighbor(nums,i))
                return false;
        }
        return true;
    }
};