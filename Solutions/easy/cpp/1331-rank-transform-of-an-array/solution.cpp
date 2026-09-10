class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty())
            return {};

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        for(int i = 0; i < arr.size(); ++i)
            pq.emplace(arr[i], i);

        int last = pq.top().first;
        int rank = 1;
          
        vector<int> ans(arr.size());

        while(!pq.empty()){
            auto [n, idx] = pq.top();
            pq.pop();

            if(n != last)
                ++rank;

            ans[idx] = rank;

            last = n;
        }

        return ans;
    }
};