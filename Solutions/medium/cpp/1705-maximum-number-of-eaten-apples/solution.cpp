class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap; //{expire time, amount}
        const int n = apples.size();

        int ans = 0;
        for (int day = 0; day < n; day++) {
            // 1. Adiciona só as maçãs que nascem hoje
            if (apples[day] > 0)
                minHeap.push({day + days[day], apples[day]});
            
            // 2. Remove lotes expirados
            while (!minHeap.empty() && minHeap.top().first <= day)
                minHeap.pop();

            // 3. Come 1 maçã do lote com menor validade
            if(!minHeap.empty()){
                const auto [expireTime, amount] = minHeap.top();
                ++ans;
                minHeap.pop();
                if(amount > 1){
                    minHeap.push({expireTime, amount-1});
                }
            }
        }
        
        // Processa o que sobrou
        int day = n;
        while (!minHeap.empty()) {
            while (!minHeap.empty() && minHeap.top().first <= day)
                minHeap.pop();

            if (minHeap.empty()) break;

            auto [expireTime, amount] = minHeap.top();
            minHeap.pop();
            ans++;

            if (amount > 1)
                minHeap.push({expireTime, amount - 1});

            day++;
        }

        return ans;

    }
};