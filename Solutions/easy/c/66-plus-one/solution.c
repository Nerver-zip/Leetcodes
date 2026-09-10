/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *array, int size, int *returnSize){
    bool flag = true;
    //special case
    for (int i = 0; i < size; i++)
    {
        if (array[i] != 9)
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        int *newArray = (int*)malloc(sizeof(int) * (size + 1));
        *returnSize = size+1;
        newArray[0] = 1;
        for (int i = 1; i < (*returnSize); i++)
        {
            newArray[i] = 0;
        }
        return newArray;
    }
    //regular case
    int *newArray = (int*)malloc(sizeof(int) * size);
    bool carry = array[size-1] + 1 > 9;
    newArray[size-1] = carry ? 0 : array[size-1] + 1; 
    for (int i = size-2; i >= 0; i--)
    {
        if ((array[i] + carry) > 9)
        {
            newArray[i] = 0;
        }
        else
        {
            newArray[i] = array[i] + carry;
            carry = false;
        }
    }
    *returnSize = size;
    return newArray;
}