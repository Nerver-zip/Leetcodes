class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size()-1;

        while (left <= right) {
            int mid = left + (right-left)/2;
            
            if(mid > 0 && mid < arr.size()-1 && arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1])
                return mid;
            if(mid > 1 && arr[mid-2] < arr[mid-1] && arr[mid-1] > arr[mid])
                return mid-1;
            if(mid < arr.size()-2 && arr[mid+1] > arr[mid] && arr[mid+2] < arr[mid+1])
                return mid+1;
            else if(mid > 0 && arr[mid-1] < arr[mid])
                left = mid + 1;
            else
                right = mid -1;
        }
        
        return -1;
    }
};