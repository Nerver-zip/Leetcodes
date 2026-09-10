int getLastIndex(int *array, int removed,int index);
void swap(int *a,int *b);

int removeElement(int *array, int size, int val){
    int lastIndex = size-1;
    for (int i = 0; i < size && i <= lastIndex; i++)
    {
        if (array[i] == val)
        { 
            lastIndex = getLastIndex(array,val,lastIndex);
            if (lastIndex < i)
            {
                return lastIndex+1;
            }
            swap(&array[i],&array[lastIndex]);
            lastIndex--; 
        }
    }
    return lastIndex+1;
}

//gets index to last number non equal to 'removed'
int getLastIndex(int *array, int removed, int indexLast){ 
    int i = indexLast;
    for (;i > 0; i--)
    {
        if (array[i] != removed)
        {
            return i;   
        }
    }
    return i;
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}