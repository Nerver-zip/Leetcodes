class Solution {
public:
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);

        return ans;
    }

private:
    int ans = 0;
    
    void merge(vector<int>& nums, int left, int mid, int right){
        int left_size = mid - left + 1, right_size = right - mid;

        vector<int> left_arr, right_arr;

        for(int i = 0; i < left_size; ++i)
            left_arr.push_back(nums[left + i]);

        for(int i = 0; i < right_size; ++i)
            right_arr.push_back(nums[mid + 1 + i]);


        //Before merging, solve subproblem with two pointers
        [&](){
            int j = 0;
            for (int i = 0; i < left_size; ++i) {
                while(j < right_size && 1LL * left_arr[i] > right_arr[j] * 2LL)
                    ++j;
                ans += j;
            }
        }();

        int i = 0, j = 0, k = left;

        while (i < left_size && j < right_size) {
            if(left_arr[i] <= right_arr[j]){
                nums[k] = left_arr[i];
                ++i;
            }
            else{
                nums[k] = right_arr[j];
                ++j;
            }
            ++k;
        }
        
        while (i < left_size) {
            nums[k] = left_arr[i];
            ++k;
            ++i;
        }

        while (j < right_size) {
            nums[k] = right_arr[j];
            ++k;
            ++j;
        }
    }

    void mergeSort(vector<int>& nums, int left, int right){
        if (left < right) {
            int mid = left + (right-left)/2;
            mergeSort(nums, left, mid);
            mergeSort(nums, mid+1, right);
            merge(nums, left, mid, right);
        }
    }
};