class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size();
        const int m = nums2.size();

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0; 
        while(i < n && j < m){
            while(i < n && j < m && nums1[i] < nums2[j])
                ++i;
            while(i < n && j < m && nums2[j] < nums1[i])
                ++j;
            if(i < n && j < m && nums1[i] == nums2[j])
                return nums1[i];
        }
        return -1;
    }
};