class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        vector<int> prefix(s.size() + 1,0);

    for (const auto& shift : shifts) {
        int L = shift[0]; 
        int R = shift[1]; 
        int D = shift[2]; 

        int displacement = (D == 1) ? 1 : -1;
         
        prefix[L] += displacement;
        if (R + 1 < s.size()) {
            prefix[R + 1] -= displacement;
        }
    }

    for (int i = 1; i < s.size(); ++i) {
        prefix[i] += prefix[i - 1];
    }
        
        string ans;

        for (int i = 0; i < s.size(); i++)
        {
            int shift = prefix[i] % 26;
            int curr = s[i] - 'a';
            int new_index = (curr + shift + 26) % 26;

            char newChar = 'a' + new_index;

            ans += newChar;
        }
        
        return ans;
    }
};
