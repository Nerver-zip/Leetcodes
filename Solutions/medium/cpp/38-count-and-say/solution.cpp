class Solution {
public:
    vector<pair<char,int>> mapString(const string& s){
        vector<pair<char,int>> mapped;

        int count = 1;
        char prev = s[0];
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == prev)
            {
                count++;
            }
            else 
            {
                mapped.push_back({prev, count});
                count = 1;
            }
            prev = s[i];
        }
        mapped.push_back({prev, count});
        return mapped;
    }

    string buildString(const vector<pair<char,int>>& map){
        string s;
        for (const auto& [c, count] : map){
            s += std::to_string(count) + c;
        }
        return s;
    }

    string countAndSay(int n) {
        string s = "1";

        for (int i = 0; i < n - 1; i++){
            vector<pair<char, int>> mapped = mapString(s);
            s = buildString(mapped);
        }
        
        return s;
    }
};