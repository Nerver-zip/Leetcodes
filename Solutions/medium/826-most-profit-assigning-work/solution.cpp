class Solution {
private:
    int binarySearchLowerBound(const vector<int>& nums, int left, int right, int target){
        int index = -1;
        while (left <= right)
        {
            int mid = left + (right-left)/2;
            if (nums[mid] >= target)
            {
                index = mid;
                right = mid - 1;
                
            }
            else
                left = mid + 1;   
        }
        return index;
    }
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(), worker.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq; //profit, dificulty

        for (int i = 0; i < difficulty.size(); i++)
            pq.push({profit[i],difficulty[i]});

        int right = worker.size()-1;
        int ans = 0;
        while (!pq.empty() && right >= 0)
        {
            auto [prof, diff] = pq.top();
            pq.pop();
            int left = binarySearchLowerBound(worker, 0, right, diff);
            if (left != -1)
            {
                int assigned = right - left + 1;
                right = left-1;
                ans += assigned * prof;
            }
        }
        return ans;
    }
};