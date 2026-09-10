class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int expectedSum = 0;
        int sum = 0;
        int partitions = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            expectedSum += i;
            if (arr[i] + sum == expectedSum)
            {
                partitions++;
            }
            sum += arr[i];
               
        }
        return partitions;
    }
};
