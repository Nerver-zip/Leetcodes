class Solution {
private:
    bool digitSumSymmetric(int n){
        int size = 0;
        int x = n;
        while (x)
        {
            x /= 10;
            size++;
        }
        
        if(size % 2 != 0) return false;
        
        int firstHalf = 0;
        int secondHalf = 0;

        int i = 0;
        while (size/2 > i)
        {
            firstHalf += n % 10;
            n /= 10;
            i++;
        }
        
        i = 0;
        while (size/2 > i)
        {
            secondHalf += n % 10;
            n /= 10;
            i++;
        }

        return firstHalf == secondHalf;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++)
        {
            if(digitSumSymmetric(i))
                count++;
        }
        return count;
    }
};