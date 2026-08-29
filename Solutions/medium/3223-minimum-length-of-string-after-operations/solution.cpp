class Solution {
public:
    int minimumLength(string s) {
        vector<int> letterCount(26,0);

        for(const auto& c : s){
            letterCount[c - 'a']++;
        }

        int count = 0;
        for (int i = 0; i < letterCount.size(); i++)
        {
            if (letterCount[i] >= 3)
            {
                if(letterCount[i] % 2 == 0)
                    count += letterCount[i] - 2;
                else
                    count += letterCount[i] - 1;    
            }
            
        }
        return s.size() - count;
    }
};