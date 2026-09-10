class Solution {
private:
    int numSize(int num){
        int count = 0;
        while (num)
        {
            num /= 10;
            count++;
        }
        return count;
    }
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (const auto& n : nums)
            if(numSize(n) % 2 == 0)
                count++;
        return count;
    }
};