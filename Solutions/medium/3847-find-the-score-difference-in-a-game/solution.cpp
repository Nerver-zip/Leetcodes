class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        bool first = true, second = false;
        int firstRes = 0, secondRes = 0;

        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] & 1){
                bool temp = first;
                first = second;
                second = temp;
            }
            if((i+1) % 6 == 0) {
                bool temp = first;
                first = second;
                second = temp;
            }
            if(first){
                firstRes += nums[i];
            }
            else {
                secondRes += nums[i];
            }
        }

        return firstRes - secondRes;
    }
};