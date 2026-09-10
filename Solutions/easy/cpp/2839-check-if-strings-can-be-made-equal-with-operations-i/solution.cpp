class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        unordered_set<char> charSet1(s2.begin(), s2.end()), charSet2(s2.begin(), s2.end());
        
        if(charSet1 != charSet2)
            return false;

        unordered_set<string> s1Set, s2Set;
        vector<string> s1Perm, s2Perm;
        
        s1Perm.push_back(s1);
        s1Set.insert(s1);
        for (size_t i = 0; i < s1Perm.size(); ++i){
            swap(s1Perm[i][0], s1Perm[i][2]);
            if(!s1Set.count(s1Perm[i])){
                s1Perm.push_back(s1Perm[i]);
                s1Set.insert(s1Perm[i]);
            }
            swap(s1Perm[i][0], s1Perm[i][2]); // backtrack
            
            swap(s1Perm[i][1], s1Perm[i][3]);
            if(!s1Set.count(s1Perm[i])){
                s1Perm.push_back(s1Perm[i]);
                s1Set.insert(s1Perm[i]);
            }
            swap(s1Perm[i][1], s1Perm[i][3]); // backtrack
        }
        
        
        s2Perm.push_back(s2);
        s2Set.insert(s2);
        for (size_t i = 0; i < s2Perm.size(); ++i){
            swap(s2Perm[i][0], s2Perm[i][2]);
            if(s1Set.count(s2Perm[i]))
                return true;

            if(!s2Set.count(s2Perm[i])){
                s2Perm.push_back(s2Perm[i]);
                s2Set.insert(s2Perm[i]);
            }
            swap(s2Perm[i][0], s2Perm[i][2]);
            

            swap(s2Perm[i][1], s2Perm[i][3]);
            if(s1Set.count(s2Perm[i]))
                return true;
            
            if(!s2Set.count(s2Perm[i])){
                s2Perm.push_back(s2Perm[i]);
                s2Set.insert(s2Perm[i]);
            }
            swap(s2Perm[i][1], s2Perm[i][3]);
        }

        return false;
    }
};