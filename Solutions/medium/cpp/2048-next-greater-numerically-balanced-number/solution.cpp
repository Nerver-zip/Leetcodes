class Solution {
public:
    int nextBeautifulNumber(int n) {
        for (int x = n + 1; x <= 1224444; ++x) {
            if (isBalanced(x))
                return x;
        }
        return -1;
    }

private:
    bool isBalanced(int n){
        
        array<int, 10> freq{};

        while (n) {
            int digit = n % 10;
            if(digit == 0 || digit == 7 || digit == 8 || digit == 9)
                return false;
            ++freq[digit];
            n /= 10;
        }
        
        for (int i = 1; i < 10; ++i) {
            if(freq[i] && i != freq[i])
                return false;
        }

        return true;
    }
};