#include <limits.h>
#include <math.h>

bool isPalindrome(int num){
    int size = lenght(num) + 1;
    char *numChar = (char*)malloc(sizeof(char) * size);
    sprintf(numChar,"%d",num);
    int j = size-2;

    for (int i = 0; i < size/2; i++)
    {
        if (numChar[i] != numChar[j])
        {
            free(numChar);
            return false;
        }
        j--;   
    }
    free(numChar);
    return true;
}

int lenght(int num){
    int len;
    if (num == INT_MIN)
    {
        return 11;
    }
    if (abs(num)) 
    { 
    len = floor(log10(abs(num)) + 1); 
        if (num < 0) // '- sign'
        {
            len++;
        }
    } 
    else //0 case
    {       
    len = 1;
    }
    return len;
}