class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int> ans;
        int sz = to_string(high).size();
        
        for(char d = '1'; d <= '9'; ++d){
            string s;
            for(char c = d; c <= '9' && s.size() < sz; ++c){
                s += c;
                int n = stoi(s);
                if(n >= low && n <= high)
                    ans.push_back(n);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};