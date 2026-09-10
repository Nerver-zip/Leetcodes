class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);

        for (char& c : s)
            if(c == '6'){
                c = '9';
                return atoi(s.c_str());
            }

        return atoi(s.c_str());
    }
};