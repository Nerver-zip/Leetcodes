using ll = long long;

// when selecting a pair from two sorted list,
// the smallest next pair is either going to be
// i+1, j or i, j+1
// similar to navigating in a sorted matrix

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> minHeap; //{sum, i, j}

        minHeap.push({nums1[0]+nums2[0], 0, 0});
        vector<vector<int>> ans;

        auto pack = [&](int i, int j) {
            return ((long long)i << 32) | j;
        };
        
        unordered_set<long long> seen;
        
        seen.insert(pack(0,0));
        
        while (!minHeap.empty() && k--) {
            auto [_, i, j] = minHeap.top();
            
            ans.push_back({nums1[i],nums2[j]});
            
            minHeap.pop();

            if(j < nums2.size()-1){
                ll key = pack(i, j+1);
                if(!seen.count(key)){
                    minHeap.push({nums1[i] + nums2[j+1], i, j+1});
                    seen.insert(key);
                }
            }

            if(i < nums1.size()-1){
                ll key = pack(i+1, j);
                if(!seen.count(key)){
                    minHeap.push({nums1[i+1] + nums2[j], i+1, j});
                    seen.insert(key);
                }
            }
        }
        return ans; 
    }
};