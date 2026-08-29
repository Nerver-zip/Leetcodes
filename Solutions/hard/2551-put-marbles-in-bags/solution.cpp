class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        std::priority_queue<long long> cutsMaxHeap;
        std::priority_queue<long long, vector<long long>, std::greater<>> cutsMinHeap;

        for (int i = 0; i < weights.size()-1; i++)
        {
            long long cut = weights[i] + weights[i+1];
            cutsMaxHeap.push(cut);
            cutsMinHeap.push(cut);
        }
        int cuts = 0;
        long long max = 0;
        long long min = 0;
        while (cuts < k-1)
        {
            max += cutsMaxHeap.top();
            cutsMaxHeap.pop();
            min += cutsMinHeap.top();
            cutsMinHeap.pop();
            cuts++;
        }
        return max - min;
    }
};