class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        std::priority_queue<int> myQueue;
        long long remainder = 0;

        for (auto gift : gifts)
        {
            myQueue.push(gift);
        }
        
        for (int i = 0; i < k; i++)
        {
            myQueue.push(sqrt(myQueue.top())); 
            myQueue.pop();   
        }

        while (!myQueue.empty())
        {
            remainder += myQueue.top();
            myQueue.pop();
        }
        return remainder;    
    }
};
