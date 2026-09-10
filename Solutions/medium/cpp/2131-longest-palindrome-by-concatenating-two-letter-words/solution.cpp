class Solution {
private:
    string reversed(const string& str){
        return string() + str[1] + str[0];
    }
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> heterogenMap;
        unordered_map<string, int> homogenMap;
        
        int count = 0;
        for (const auto& word : words)
        {
            string rev = reversed(word);
            if (word[0] == word[1])
                homogenMap[word]++;
            else 
                heterogenMap[word]++;
            if (heterogenMap[word] > 0 && heterogenMap[rev] > 0)
            {
                heterogenMap[word]--;
                heterogenMap[rev]--;
                count += 4;
            }
        }

        bool hasPutOdd = false;
        for (const auto& [_, freq] : homogenMap)
        {
            if (freq % 2 == 1)
            {
                //place at most one odd freq
                if (!hasPutOdd){
                    count += freq * 2;
                    hasPutOdd = true;
                }
                //select an even number of that odd freq
                else
                    count += (freq - 1) * 2;
            }
            //place as many even freq as possible
            else
                count += freq * 2;
        }
        return count;
    }
};