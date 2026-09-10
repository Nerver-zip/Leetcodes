int removeDuplicates(int *array, int size){
    int newSize = 1;
    int greatest = array[size-1];

    if(size == 0)
    {
        return 0;
    }

    if (greatest == array[0])
    {
        return newSize;
    }

    for (int incialIndex = 0; incialIndex < size-1; incialIndex++)
    {
        if (array[incialIndex] == greatest)
        {
            return newSize;
        }
            int finalIndex = incialIndex+1;
            if (array[incialIndex] != array[finalIndex])
            {
                newSize++;
                continue;
            }
            while (array[incialIndex] == array[finalIndex] && finalIndex < size)
            {
                if (greatest == array[finalIndex])
                {
                    return newSize;
                }
                finalIndex++;
            }
                shift(array,incialIndex+1,finalIndex,size);
                newSize++;
    }
    return size;
}
void shift(int *array, int incialIndex, int replacementIndex, int size){

    for (int i = incialIndex; i < size && replacementIndex < size; i++)
    {
        array[i] = array[replacementIndex++];
    }
}