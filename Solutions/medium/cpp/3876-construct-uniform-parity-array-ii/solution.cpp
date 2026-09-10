class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT32_MAX;

        for(int n : nums1)
            if(n & 1)
                minOdd = min(minOdd, n);

        bool canTransformEven = true, canTransformOdd = true;

        // Transform into odd
        for(int n : nums1){
            if(n % 2 == 0 && n - minOdd < 1){
                canTransformOdd = false;
                break;
            }
        }

        // Transform into even
        for(int n : nums1){
            if(n & 1 && n - minOdd < 1){
                canTransformEven = false;
                break;
            }
        }

        return canTransformEven || canTransformOdd;
    }
};