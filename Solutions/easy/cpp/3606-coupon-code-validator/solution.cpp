class Solution {
private:
    static inline unordered_set<string> business = {"electronics", "grocery", "pharmacy", "restaurant"};
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        const int size = code.size();
        vector<vector<string>> sorted;
        bool abort = false;

        for (int i = 0; i < size; ++i)
        {
            abort = false;
            if(!isActive[i])
                continue;
            if(code[i].size() == 0 || businessLine[i].size() == 0)
                continue;
            string currCode = code[i];
            string currBusinesLine = businessLine[i];
            for (int j = 0; j < currCode.size(); ++j)
                if(!(currCode[j] == '_') && (currCode[j] < '0' || (currCode[j] > '9' && currCode[j] < 'A') || (currCode[j] > 'Z' && currCode[j] < 'a') || currCode[j] > 'z')){
                    abort = true;
                    break;
                }                   
            if(abort) continue;
            if(business.find(currBusinesLine) == business.end())
                continue;
            sorted.push_back({code[i], businessLine[i]});
        }
        
        sort(sorted.begin(), sorted.end(), [](const auto& a, const auto& b){
            return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
        });

        vector<string> ans;

        for (const auto& code : sorted)
            ans.push_back(code[0]);
        
        return ans;
    }
};