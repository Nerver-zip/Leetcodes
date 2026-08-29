class Solution {
private:
    int getMax(const vector<int>& nums){
        int max = INT32_MIN;
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > max){
                max = nums[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<>> freeRooms; //{}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> occupiedRooms; //{occupied until, roomId index}
        vector<int> ans(n, 0);
        
        sort(meetings.begin(), meetings.end());

        for (int i = 0; i < n; ++i)
            freeRooms.push(i);

        for (const auto& meeting : meetings)
        {
            int start = meeting[0], end = meeting[1];
            long long duration = end - start;

            while(!occupiedRooms.empty() && start >= occupiedRooms.top().first)
            {
                int roomId = occupiedRooms.top().second;
                freeRooms.push(roomId);
                occupiedRooms.pop();
            }
        
            if (freeRooms.size() != 0)
            {
                int roomId = freeRooms.top();
                occupiedRooms.push({start + duration, roomId});
                freeRooms.pop();
                ++ans[roomId];
            }
            else
            {
                auto [currDuration, roomId] = occupiedRooms.top();
                occupiedRooms.pop();
                occupiedRooms.push({currDuration + duration, roomId});
                ++ans[roomId];
            }
        }
        return getMax(ans);
    }
};