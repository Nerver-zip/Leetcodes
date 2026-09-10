class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> visited(n);
        unordered_set<int> locked;
        unordered_set<int> myKeys;

        queue<int> q;
        int totalCandies = 0;

        for (int i = 0; i < initialBoxes.size(); ++i)
            if(status[initialBoxes[i]])
                q.push(initialBoxes[i]);
            else
                locked.insert(initialBoxes[i]);

        while (!q.empty())
        {
            auto box = q.front();
            q.pop();

            //if it was already visited or is not opened and no key, skip
            if(visited[box])
                continue;
            if(!status[box] && myKeys.find(box) == myKeys.end()){
                locked.insert(box);
                continue;
            }
            
            //get candies
            totalCandies += candies[box];

            visited[box] = true;
            
            //get all keys
            for (const auto& key : keys[box])
                myKeys.insert(key);

            //get all boxes
            for (const auto& containedBox : containedBoxes[box])
                if(!visited[containedBox])
                    if(status[containedBox] || myKeys.find(containedBox) != myKeys.end())
                        q.push(containedBox);
                    else
                        locked.insert(containedBox);
            
            //scan for boxes that can be openable
            for (auto it = locked.begin(); it != locked.end();)
            {
                if (!visited[*it] && myKeys.find(*it) != myKeys.end()){
                    q.push(*it);
                    it = locked.erase(it);
                }
                else
                    ++it;
            }
        }
        return totalCandies;
    }
};