class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        
        unordered_map<int, int> freq;
        set<pair<int,int>, greater<>> topX, rest; //{freq, n}
        long long sumTop = 0;
        vector<long long> ans;

        auto fixTop = [&]() {
            while (topX.size() > x) {
                auto it = prev(topX.end());
                sumTop -= 1LL * it->first * it->second;
                rest.insert(*it);
                topX.erase(it);
            }
            while (topX.size() < x && !rest.empty()) {
                auto it = rest.begin();
                sumTop += 1LL * it->first * it->second;
                topX.insert(*it);
                rest.erase(it);
            }
        };

        auto add = [&](int n) {
            int f = freq[n];
            pair<int,int> oldp = {f,n};
            pair<int,int> newp = {f+1,n};

            if (f > 0) {
                if (topX.erase(oldp))
                    sumTop -= 1LL * oldp.first * oldp.second;
                else
                    rest.erase(oldp);
            }

            freq[n] = f+1;

            if (topX.size() < x) {
                topX.insert(newp);
                sumTop += 1LL * newp.first * newp.second;
            } else {
                auto worst = prev(topX.end());
                if (*worst < newp) {
                    // substitui o pior do top
                    sumTop -= 1LL * worst->first * worst->second;
                    rest.insert(*worst);
                    topX.erase(worst);
                    topX.insert(newp);
                    sumTop += 1LL * newp.first * newp.second;
                } 
                else
                    rest.insert(newp);
            }
        };

        auto remove = [&](int n) {
            int f = freq[n];
            if (f == 0) 
                return;
            
            pair<int,int> oldp = {f,n};
            
            if (topX.erase(oldp))
                sumTop -= 1LL * oldp.first * oldp.second;
            else
                rest.erase(oldp);

            freq[n] = f-1;
            
            if (freq[n] > 0)
                rest.insert({freq[n], n});

            fixTop();
        };

        for (size_t right = 0, left = 0; right < nums.size(); ++right) {
            add(nums[right]);

            while (right - left + 1 > k)
                remove(nums[left++]);

            if(right - left + 1 == k)
                ans.push_back(sumTop);
        }

        return ans;
    }
};