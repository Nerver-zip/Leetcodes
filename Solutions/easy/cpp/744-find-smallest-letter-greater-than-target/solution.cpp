class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];

        for(char c : letters)
            if(c > target)
                return c;

        return ans;
    }
};