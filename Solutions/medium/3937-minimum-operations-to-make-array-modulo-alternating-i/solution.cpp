class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        const int n = nums.size();

        if(n == 1)
            return 0;

        vector<int> oddRemainders, evenRemainders;

        for(int i = 0; i < n; ++i){
            if(i & 1)
                oddRemainders.push_back(nums[i] % k);
            else
                evenRemainders.push_back(nums[i] % k);    
        }
        
        int prevX, prevY, minOpEven, minOpOdd;
        minOpEven = minOpOdd = prevY = prevX = numeric_limits<int>::max();
        
        int y = oddRemainders.front();
        for(int i = 0; i < k; ++i){
            int operations = 0;
            for(int j = 0; j < oddRemainders.size(); ++j){
                operations += min(abs(i - oddRemainders[j]), k - abs(i - oddRemainders[j]));
            }
            if(minOpOdd >= operations){
                y = i;
                prevY = minOpOdd;
                minOpOdd = operations;
            }
            else if(prevY > operations){
                prevY = operations;
            }
        }

        int x = evenRemainders.front();
        for(int i = 0; i < k; ++i){
            int operations = 0;
            for(int j = 0; j < evenRemainders.size(); ++j){
                operations += min(abs(i - evenRemainders[j]), k - abs(i - evenRemainders[j]));
            }
            if(minOpEven >= operations){
                x = i;
                prevX = minOpEven;
                minOpEven = operations;
            }
            else if(prevX > operations){
                prevX = operations;
            }
        }

        if(x == y){
            if(prevX == numeric_limits<int>::max() && prevY == numeric_limits<int>::max()){
                return min(minOpOdd + evenRemainders.size(), minOpEven + oddRemainders.size());
            }
            return min(prevX + minOpOdd, prevY + minOpEven); 
        }

        return minOpOdd + minOpEven;
    }
};