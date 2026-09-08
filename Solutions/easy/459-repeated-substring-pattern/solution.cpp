class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string original = s;
        
        //Rotation: duplicate string, cut first pos and last pos and search for og in the new string

        s.append(s, 0, s.size());
        s = s.substr(1);
        s.pop_back();
        
        int res = s.find(original);
        
        return res == -1 ? false : true;
    }
};