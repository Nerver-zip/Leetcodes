class Solution { //Naive solution -> merge algorithm
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        bool isEvenSize = size % 2 == 0 ? true : false;
        int *array = new int[size];
        if(size == 0) return 0;
        size = size/2;
        int i = 0;
        int j = 0;
        int k = 0;
        
        while (i < nums1.size() && j < nums2.size() && k <= size)
        {
            if (nums1[i] < nums2[j])
            {
                array[k] = nums1[i];
                i++;
                k++;
            }
            else
            {
                array[k] = nums2[j];
                j++;
                k++;
            }
        }
        if (k <= size)
        {
            while (i < nums1.size())
            {
                array[k] = nums1[i];
                i++;
                k++;
            }
            while (j < nums2.size())
            {
                array[k] = nums2[j];
                j++;
                k++;
            }
        }
        double median = isEvenSize ? (array[size] + array[size-1])/2.0 : array[size];
        delete[] array;
        array = nullptr;
        return median;   
    }
};