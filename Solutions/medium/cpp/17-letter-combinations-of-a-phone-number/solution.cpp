class Solution {
private:

    std::unordered_map<int,vector<char>> digitMap {
        {'2',{'a','b','c'}},
        {'3',{'d','e','f'}},
        {'4',{'g','h','i'}},
        {'5',{'j','k','l'}},
        {'6',{'m','n','o'}},
        {'7',{'p','q','r','s'}},
        {'8',{'t','u','v'}},
        {'9',{'w','x','y','z'}}
    };

    vector<string> ans;

    void combinate(string res, string digits, int index){
        if(index == digits.size()){
            ans.push_back(res);
        }
        for (const auto& letter : digitMap[digits[index]])
        {
            res += letter;
            combinate(res,digits,index+1);
            res.pop_back(); //backtrack
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string res;
        if (digits.size() == 0)
            return {};
        combinate(res,digits,0);
        return ans;
    }
};