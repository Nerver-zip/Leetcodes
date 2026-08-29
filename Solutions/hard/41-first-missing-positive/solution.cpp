//Idea: Use input array to mark elements as visited
//This is tricky, we can do this because negative numbers doesnt matter
//And also duplicates doesnt interfere with the result
//So we can scan the arr 3 times:
//1st one -> Sanitize the input marking negative values as 0
//2nd one -> For each number, compute idx = abs(n) - 1, and if idx is in bounds
//set the element mapped by idx to negative, essentially marking it as visited (think of this like a hashset)
//3rd one -> Evaluate the possible answers [1, N], return the first number that do not appear
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int& n : nums)
            if(n < 0)
                n = 0;

        for (int& n : nums) {
            int idx = abs(n) - 1;
            if(idx < nums.size()){
                if(nums[idx] == 0)
                    nums[idx] = abs(n) * -1; //if OG number was negative, we can do this because reading the same number again won't matter (check testcase 2)  
                else
                    nums[idx] = abs(nums[idx]) * -1; //Else mark as seen but preserving the OG absolute value
            }
        }

        for (int n = 1; n <= nums.size(); ++n) {
            if(nums[n-1] >= 0)
                return n;
        }

        return nums.size() + 1;
    }
};