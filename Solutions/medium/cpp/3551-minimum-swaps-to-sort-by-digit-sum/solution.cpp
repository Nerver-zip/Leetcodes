class Solution {
private:
    int digitSum(int n){
        int sum = 0;
        while (n)
        {
            sum += n % 10;
            n /= 10;
        }
    return sum;
}
public:
    int minSwaps(vector<int>& nums) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<>> minHeap;
        unordered_map<int, int> indexMap;

        for (int i = 0; i < nums.size(); i++){
            minHeap.push({digitSum(nums[i]), nums[i]});
            indexMap[nums[i]] = i;
        }
        
        int count = 0;
        int i = 0;
        while (!minHeap.empty())
        {
            auto [sum, num] = minHeap.top();
            minHeap.pop();
            if(i != indexMap[num]){
                count++;
                int temp = indexMap[num];
                indexMap[num] = i;
                indexMap[nums[i]] = temp;
                swap(nums[i], nums[temp]);
            }
            i++;
        }
        return count;
    }
};