class Solution {
private:
    int countDeletions(const vector<int>& freq, char c, int min, int k){
        int deletions = 0;
        for (int i = 0; i < 26; ++i)
            if (i + 'a' != c && freq[i] > 0 && freq[i] > k + min)
                deletions += freq[i] - (k + min);
        return deletions;
    }
public:
    int minimumDeletions(string word, int k) {
        vector<int> freqMap(26, 0);
        priority_queue<pair<int, char>, vector<pair<int,char>>, greater<>> minHeap; //{freq, char}

        for (char c : word)
            freqMap[c - 'a']++;
        
        for (int i = 0; i < 26; ++i)
            if(freqMap[i] != 0)
                minHeap.push({freqMap[i], i + 'a'});

        int minimumDeletions = INT_MAX, deletedChars = 0, currMinDeletions;
        
        while (!minHeap.empty())
        {
            auto [minFreq, minChar] = minHeap.top();
            minHeap.pop();

            currMinDeletions = countDeletions(freqMap, minChar, minFreq, k) + deletedChars;
            minimumDeletions = min(minimumDeletions, currMinDeletions);

            deletedChars += freqMap[minChar - 'a'];
            freqMap[minChar - 'a'] = 0;
        }
        
        return minimumDeletions;
    }
};