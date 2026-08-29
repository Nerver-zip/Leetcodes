class Solution {
private:
    bool canBeAssigned(const vector<int>& tasks, const vector<int>& workers, int k, int pills, int strenght){

        std::multiset<int> strongestWorkers(workers.end() - k, workers.end());

        for (int i = k-1; i >= 0; i--)
        {
            int task = tasks[i];
            auto it = strongestWorkers.lower_bound(task);
            if (it != strongestWorkers.end())
                strongestWorkers.erase(it);
            else 
            {
                if(pills == 0)
                    return false;
                it = strongestWorkers.lower_bound(task - strenght);
                if (it == strongestWorkers.end())
                    return false;
                strongestWorkers.erase(it);
                pills--;
            }
        }
        return true;
    }
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        std::sort(tasks.begin(), tasks.end());
        std::sort(workers.begin(), workers.end());

        int left = 0;
        int right = std::min(tasks.size(), workers.size());

        int mid;
        int ans = 0;
        while (left <= right)
        {
            mid = left + (right-left)/2;
            if (canBeAssigned(tasks, workers, mid, pills, strength))
            {
                ans = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return ans;
    }
};