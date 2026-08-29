int singleNumber(int *array, int size) {
    int single = 0;
    for (int i = 0; i < size; i++)
    {
        single ^= array[i];
    }
    return single;
}