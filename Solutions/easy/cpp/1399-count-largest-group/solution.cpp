class Solution {
private:
    int digitSum(int x){
        int sum = 0;
        while (x)
        {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> frequencyMap;


        for (int i = 1; i <= n; i++)
            frequencyMap[digitSum(i)]++;
        
        int max = frequencyMap.begin()->second;
        int count = 0;
        
        for (const auto& [sum, freq] : frequencyMap)
        {
            if (freq > max)
            {
                max = freq;
                count = 1;
            }
            else if(freq == max)
                count++;
        }
        return count;
    }
};