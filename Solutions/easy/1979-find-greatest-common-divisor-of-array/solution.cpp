class Solution {
public:
    int findGCD(vector<int>& nums) {
        int greatest = nums[0];
        int smallest = nums[0];

        for(int n : nums){
            greatest = max(greatest, n);
            smallest = min(smallest, n);
        }

        return gcd(greatest, smallest);
    }
};