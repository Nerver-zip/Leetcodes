class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1)
            return word;
        const int size = word.size();
        string ans = word.substr(0, size - numFriends + 1);
        
        for (int i = 0; i < size; ++i)
        {
            string curr = word.substr(i, size - numFriends + 1);
            if(ans < curr)
                ans = curr;
        }
        return ans;
    }
};