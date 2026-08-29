int majorityElement(int *array, int size) {
    int majority;
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (count == 0)
        {
            majority = array[i];
            count++;
        }
        else if (majority == array[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count > size/2)
        {
            return majority;
        } 
    }
    return majority;
}