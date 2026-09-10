class Solution {
public:
    string reformatDate(string date) {
        stringstream ss(date);
        string token;

        vector<string> tokens;

        while (ss >> token) {
            tokens.push_back(token);
        }
        
        auto& tk = tokens[0];
        if(tokens[0].size() == 3){
            string newToken = "0";
            newToken += tk;
            tk = newToken;
        }

        return tokens[2] + "-" + map[tokens[1]] + "-" + tokens[0].substr(0,2);
    }

private:
    static inline unordered_map<string, string> map = {
        {"Jan", "01"},
        {"Feb", "02"},
        {"Mar", "03"},
        {"Apr", "04"},
        {"May", "05"},
        {"Jun", "06"},
        {"Jul", "07"},
        {"Aug", "08"},
        {"Sep", "09"},
        {"Oct", "10"},
        {"Nov", "11"},
        {"Dec", "12"}
    };
};