class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
private:
    random_device r;  // fonte de entropia
    mt19937 gen{r()}; // Mersenne Twister
     


    void threeWayPartition(vector<int>& nums, int l, int r, int& lt, int& gt) {
        // pivô aleatório
        uniform_int_distribution<int> dist(l, r);
        int pivotIndex = dist(gen);
        int pivot = nums[pivotIndex];
        swap(nums[l], nums[pivotIndex]); // coloca pivô no início

        lt = l;        // nums[l..lt-1] < pivot
        gt = r;        // nums[gt+1..r] > pivot
        int i = l + 1; // nums[lt..i-1] == pivot

        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[lt]);
                lt++;
                i++;
            } else if (nums[i] > pivot) {
                swap(nums[i], nums[gt]);
                gt--;
            } else { // nums[i] == pivot
                i++;
            }
        }
    }


    void quickSort(vector<int>& nums, int l, int r){
        if(l < r){
            int lt, gt;
            threeWayPartition(nums, l, r, lt, gt);
            quickSort(nums, l, lt - 1);
            quickSort(nums, gt+1, r);
        }
    }
};
