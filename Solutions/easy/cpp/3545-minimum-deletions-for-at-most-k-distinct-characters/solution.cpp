class Solution {
public:
    int minDeletion(string s, int k) {
       vector<int> freqMap(26, 0);
       
        for (int i = 0; i < s.size(); ++i)
            freqMap[s[i] - 'a']++;

        int count = 0;
        for (const auto& c : freqMap)
            if(c != 0)
                count++;

        int toDelete = count - k;
        
        int ans = 0;

        while (toDelete > 0)
        {
            int min = *max_element(freqMap.begin(), freqMap.end());
            int indexDelete = 0;
            for (int i = 0; i < freqMap.size(); ++i)
                if (min > freqMap[i] && freqMap[i] != 0){
                    min = freqMap[i];
                    indexDelete = i;
                }
            freqMap[indexDelete] = 0;
            ans += min;
            toDelete--;
        }
        return ans;
    }
};