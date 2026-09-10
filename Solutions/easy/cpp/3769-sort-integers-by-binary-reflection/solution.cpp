class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int,int>> sorted;
        

        for (int i = 0; i < nums.size(); ++i) {
            bitset<32> bits(nums[i]);
            string s = bits.to_string();
            s = s.substr(s.find('1'));
            reverse(s.begin(), s.end());
            int transformed = toDec(s);
            sorted.push_back({transformed,i});
        }

        sort(sorted.begin(), sorted.end(), [&](const auto& a, const auto& b){
            return a.first == b.first ? nums[a.second] < nums[b.second] : a.first < b.first;
        });
        
        vector<int> ans;

        for (const auto& [_,i] : sorted) {
            ans.push_back(nums[i]);
        }

        return ans;
    }

private:
    int toDec(const string& s){
        int res = 0;
        
        int count = 0;
        for (int i = s.size()-1; i >= 0; --i) {
            if(s[i] == '1'){
                res += 1 << count;
            }
            count++;
        }

        return res;
    }
};