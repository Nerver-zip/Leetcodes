int searchInsert(int *array, int size, int target){
    if (target > array[size-1])
    {
        return size;
    }
    if (target < array[0])
    {
        return 0;
    }
    int left = 0;
    int right = size-1;

    while (left <= right)
    {   
        int middle = left + (right-left)/2;
        if (array[middle] == target)
        {
            return middle;
        }
        else if (array[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return left;
}