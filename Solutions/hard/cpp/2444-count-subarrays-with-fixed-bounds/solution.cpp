class Solution {
private:
    vector<pair<int, int>> createDivisions(const vector<int>& nums, int minK, int maxK){
        vector<pair<int,int>> divisions;
        int l = -1;
        int r = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (l == -1 && !(nums[i] < minK || nums[i] > maxK))
            {
                if (r == -1)
                    r = i;
                l = i;
            }
            else if (!(nums[i] < minK || nums[i] > maxK))
            {
                r = i;
            }
            if (l != -1 && r != -1 && (nums[i] < minK || nums[i] > maxK || i == nums.size()-1)){
                divisions.push_back({l,r});
                l = -1;
                r = -1;
            }
        }
        return divisions;
    }

    long long countSubArraysIncludingK(const vector<int>& nums, int minK, int maxK, int l, int r){
        int left = l;
        int right = l;
        int size = r+1;
        
        deque<int> minMax;
        long long ans = 0;

        for (;right < size; right++)
        {
            if (nums[right] == minK)
                minMax.push_front(nums[right]);
            else if(nums[right] == maxK)
                minMax.push_back(nums[right]);
            
            while (!minMax.empty() && minMax.front() == minK && minMax.back() == maxK)
            {
                ans += size - right;
                if (nums[left] == minK)
                    minMax.pop_front();
                else if (nums[left] == maxK)
                    minMax.pop_back(); 
                left++;
            }
        }
        return ans;
    }
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        vector<pair<int,int>> divisions = createDivisions(nums, minK, maxK);
        long long ans = 0;
        for (const auto& [left, right] : divisions)
            ans += countSubArraysIncludingK(nums, minK, maxK, left, right);
        return ans;
    }
};