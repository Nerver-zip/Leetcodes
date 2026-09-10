class Solution {
private:
    bool isVowel(char letter){
        return letter == 'a'|| letter =='e' || letter == 'i' || letter == 'o' || letter == 'u';
    }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        vector<int> vowelStrIndexMap; //this is '1 indexed', the queries are '0 indexed'
        int count = 0;
        vowelStrIndexMap.push_back(0);  

        for (const auto& word : words)
        {
            if (isVowel(word.front()) && isVowel(word.back()))
                vowelStrIndexMap.push_back(++count);
            else
                vowelStrIndexMap.push_back(count);
        }

        vector<int> ans;

        for (const auto& query : queries)
        {
            ans.push_back(vowelStrIndexMap[query[1]+1] - vowelStrIndexMap[query[0]]);            
        }
        return ans;
    }
};
