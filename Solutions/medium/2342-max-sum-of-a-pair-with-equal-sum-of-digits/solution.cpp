class Solution {
private:
    int digitSum(int number){
        int sum = 0;
        while (number)
        {
            sum += number % 10;
            number /= 10;
        }
        return sum;
    }

    void greatestValues(std::pair<int,int>& pair, int val){
        if (pair.first <= val)
        {
            pair.second = pair.first;
            pair.first = val;
            return;
        }
        if (pair.second < val)
        {
            pair.second = val;
            return;
        }
        return;
    }

public:
    int maximumSum(vector<int>& nums) {
        std::unordered_map<int,std::pair<int,int>> myMap;

        for (const auto& number : nums)
        {
            int digSum = digitSum(number);
            greatestValues(myMap[digSum],number);
        }
        
        int max = -1;
        for (const auto& [key, pair] : myMap)
        {
            if (pair.second != 0) //a pair has to be formed
                max = std::max(max,pair.first + pair.second);
        }
        return max;
    }
};