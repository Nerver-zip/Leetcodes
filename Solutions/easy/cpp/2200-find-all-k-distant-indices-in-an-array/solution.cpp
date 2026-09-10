class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        const int size = nums.size();
        queue<pair<int,int>> q; //{index, dist}
        vector<int> distances(size, INT_MAX);
        
        const vector<int> directions = {
            {-1},
            {1}
        };

        for (int i = 0; i < size; ++i)
            if(nums[i] == key){
                q.push({i, 0});
                distances[i] = 0;
            }   

        while (!q.empty())
        {
            auto [index, currDist] = q.front();
            q.pop();

            if (distances[index] < currDist)
                continue;
            
            for (const auto& direction : directions)
            {
                if (direction + index == size || direction + index < 0)
                    continue;
                int next = direction + index;
                int updatedDist = currDist + 1;
                if (distances[next] > updatedDist)
                {
                    distances[next] = updatedDist;
                    q.push({next, updatedDist});
                }
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < size; ++i)
            if(distances[i] <= k)
                ans.push_back(i);

        return ans;
        
    }
};