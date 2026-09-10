class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        
        int i = 0;
        int curr = 1;

        while (i < target.size()) {
            if(target[i] == curr){
                ans.push_back("Push");
                ++i;
            }
            else if(target[i] > curr){
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            ++curr;
        }

        return ans;

    }
};
