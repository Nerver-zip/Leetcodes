class Solution {
private:
    int duplicateCount = 0;
public:
    long long maximumSubarraySum(vector<int>& numbers, int k) {
    std::unordered_map<int,int> frequencyMap;
    long long maxSum = 0;
    int left = 0;
    int right = k;
    long long sum = 0;

    for (int i = 0; i < k; i++)
    {   
        frequencyMap[numbers[i]]++;
        if (frequencyMap[numbers[i]] > 1)
        {
            duplicateCount++;
        }
        sum += numbers[i];
    }
    maxSum = duplicateCount > 0 ? 0 : sum; 
    while (right < numbers.size())
    {
        if (frequencyMap[numbers[left]] > 1)
        {
            duplicateCount--;
        }
        frequencyMap[numbers[left]]--;  
        frequencyMap[numbers[right]]++;
        if (frequencyMap[numbers[right]] > 1)
        {
            duplicateCount++;
        }
        sum = sum - numbers[left] + numbers[right];
        if (duplicateCount == 0)
        {
            if (sum > maxSum)
            {
                maxSum = sum;
            }
        }
        left++;
        right++;
    }
    return maxSum;
    }
};