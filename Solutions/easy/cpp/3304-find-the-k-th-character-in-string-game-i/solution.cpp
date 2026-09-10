class Solution {
private:
    string nextString(const string& s){
        string newString;

        for (char c : s)
        {
            if(c == 'z')
                newString += 'a';
            else
                newString += c + 1;
        }
        return newString;
    }
public:
    char kthCharacter(int k) {
        string word = "a";

        while (word.size() < k)
            word += nextString(word);
    
        return word[k-1];
    }
};