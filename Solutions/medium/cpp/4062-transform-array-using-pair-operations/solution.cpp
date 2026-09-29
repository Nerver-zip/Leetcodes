using ll = long long;

class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        ll sumSource = accumulate(source.begin(), source.end(), 0LL);    
        ll sumTarget = accumulate(target.begin(), target.end(), 0LL);    
    
        return sumSource == sumTarget;
    }
};