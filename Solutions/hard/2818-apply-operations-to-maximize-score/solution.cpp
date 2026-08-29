#define BOUND 1000000007
class Solution {
private:
    int modExpo(int base, int exp, int mod) {
        long long result = 1;
        long long b = base;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * b) % mod;
            b = (b * b) % mod;
            exp /= 2;
        }
        return result;
    }
public:
    int maximumScore(vector<int>& nums, int k) {
        int size = nums.size();
        long long ans = 1;

        vector<int> primeScore;

        for (int i = 0; i < size; i++)
        {
            int score = 0;
            int num = nums[i];
            for (int j = 2; j <= sqrt(num); j++) { 
                if (num % j == 0) {
                    score++;
                    while (num % j == 0)
                        num /= j;
                }
            }
            if (num >= 2)
                score++;
            primeScore.push_back(score);
        }

        vector<int> leftBound(size, -1);
        vector<int> rightBound(size, size);
    
        std::stack<int> stack;
        for (int i = 0; i < primeScore.size(); i++)
        {
            while (!stack.empty() && primeScore[stack.top()] < primeScore[i])
            {
                int index = stack.top();
                stack.pop();
                rightBound[index] = i;
            }
            if(!stack.empty())
                leftBound[i] = stack.top();
            stack.push(i);
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>> maxHeap;
        for (int i = 0; i < size; i++)
            maxHeap.push({nums[i],i});
        
        while (k > 0)
        {
            auto [n, index] = maxHeap.top();
            maxHeap.pop();
            int score = primeScore[index];

            long long leftCount = index - leftBound[index];
            long long rightCount = rightBound[index] - index;

            long long count = leftCount * rightCount;
            long long operations = std::min(count, static_cast<long long>(k)); 
            int curr = modExpo(n, operations, BOUND);
            ans = (ans * curr) % BOUND;
            k -= operations;
        }
        return ans;
    }
};