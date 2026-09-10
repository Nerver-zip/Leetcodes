class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        vector<pair<long, long>> intervals;
        long long numOperations = 1;
        
        for (int i = 0; i < nums1.size(); ++i) {
            long long curr1 = nums1[i], curr2 = nums2[i];
            
            pair<int,int> p;
            p.first = min(curr1, curr2);
            p.second = max(curr1, curr2);
            
            intervals.push_back(p);

            numOperations += abs(curr1 - curr2);            
        }
        
        long long target = nums2[nums2.size()-1];
        long long minDiff = INT64_MAX;

        for (const auto& [start, end] : intervals) {
            if(target >= start && target <= end){
                return numOperations;
            }

            minDiff = min({minDiff, abs(start - target), abs(end - target)});
        }
        
        numOperations += minDiff;

        return numOperations;
    }
};