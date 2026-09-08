class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q; //{i_person}
        
        for (int i = 0; i < tickets.size(); ++i)
            q.push(i);
        
        int time = 0;
        while (!q.empty()) {
            auto i = q.front();
            ++time;
            --tickets[i];
            q.pop();

            if(tickets[k] == 0)
                return time;
             
            if(tickets[i]){
                q.push(i);
            }
        }

        return 0;
    }
};