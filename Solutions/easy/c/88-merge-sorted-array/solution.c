void merge(int *array, int size1, int m, int *array2, int size2, int n);
void shiftRight(int *array, int first,int last);

void merge(int *array, int size1, int m, int *array2, int size2, int n) {
    int i = 0;
    int j = 0;
    int last = m+j-1;
    

    if (array2 == NULL || n == 0 || size2 == 0)
    {
        return;
    }

    if (m == 0)
    {
        for (int i = 0; i < size1; i++)
        {
            array[i] = array2[i];
        }
        return;
    }

    int highest = m > n ? m : n;
    while (i <= last && j < n)
    {
        if (array[i] > array2[j])
        {
            shiftRight(array,i,last);
            array[i] = array2[j];
            j++;
            last++;
        }
        i++;
    }
    while (j < size2)
    {
        array[m+j] = array2[j];
        j++;
        i++;
    }
}

void shiftRight(int *array, int first,int last){
    while (last >= first)
    {
        array[last+1] = array[last];
        last--;
    }
}