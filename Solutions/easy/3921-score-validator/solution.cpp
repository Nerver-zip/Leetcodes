class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        vector<int> ans(2, 0);

        for(const auto& event : events){
            if(event[0] >= '0' && event[0] <= '6'){
                ans.front() += stoi(event);
            }
            else if (event == "WD")
                ++ans.front();
            else if(event[0] == 'W')
                ++ans.back();
            else if(event == "NB")
                ++ans.front();
                
            if(ans.back() == 10)
                break;
        }

        return ans;
    }
};